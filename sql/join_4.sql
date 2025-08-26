with f_food as (
    select product_id, sum(amount) as am
    from food_order
    where year(produce_date)=2022 and month(produce_date)=5
    group by product_id
),food as(
    select fp.product_id,fp.product_name,am*price as total_sales
    from food_product as fp join f_food as ff on
    ff.product_id=fp.product_id
)
select *
from food
order by total_sales desc,product_id asc;
