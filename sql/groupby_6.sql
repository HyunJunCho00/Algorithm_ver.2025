with cr as (
    select car_id,count(*) as record 
    from car_rental_company_rental_history
    where month(start_date)>=8 and month(start_date)<11
    group by car_id
), crr as(
    select month(start_date) as month, crc.car_id, count(*) as records
    from car_rental_company_rental_history as crc join cr on cr.car_id=crc.car_id
    where month(start_date)>=8 and month(start_date)<11 and cr.record>=5
    group by month(start_date),crc.car_id
    order by month asc,car_id desc
)
select * from crr
