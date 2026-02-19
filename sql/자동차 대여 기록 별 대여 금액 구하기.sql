-- 코드를 입력하세요
with truck as(
    select c.history_id,c.car_id,cc.car_type,cc.daily_fee, TIMESTAMPDIFF(DAY, start_date, end_date)+1 AS diff
    from car_rental_company_rental_history as c join car_rental_company_car as cc on c.car_id=cc.car_id 
    where cc.car_type= "트럭"
),cal as(
    select history_id,car_type,daily_fee,diff,case when diff >=90 then "90일 이상" when diff>=30 then "30일 이상" when diff>=7 then "7일 이상" else NULL end as disc
    from truck
)
select t.history_id,truncate(t.daily_fee*t.diff*(1-coalesce(p.discount_rate,0)/100),0) as fee
from cal as t left join car_rental_company_discount_plan as p on t.car_type=p.car_type and t.disc=p.duration_type
order by fee desc,t.history_id desc;
