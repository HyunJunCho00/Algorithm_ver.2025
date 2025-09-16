with us as(
    select user_id, joined
    from user_info
    where year(joined)=2021
),cnt as(
    select count(distinct user_id) as num
    from us
), os as(
    select year(o.sales_date) as year,month(o.sales_date)as month,count(distinct o.user_id) as purchased_users, round(count(distinct o.user_id)/(select num from cnt),1) as purchased_ratio
    from online_sale as o join us as u on u.user_id=o.user_id
    group by year(o.sales_date),month(o.sales_date)
    order by year asc,month asc
)
select * from os
