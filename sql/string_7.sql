SELECT distinct(c.car_id)
from car_rental_company_rental_history as c join car_rental_company_car as r on c.car_id=r.car_id
where r.car_type = "세단"  and c.start_date>='2022-10-01' and c.start_date<='2022-10-31'
order by c.car_id  desc;
