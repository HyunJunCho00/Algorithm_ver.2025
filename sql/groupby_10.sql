with food as(
    select category, max(price) as max_price
    from food_product
    group by category
)
select f.category, f.max_price,fp.product_name
from food_product as fp join food as f on
f.max_price=fp.price and f.category=fp.category
where f.category in('식용유','과자','국','김치')
order by f.max_price desc;
