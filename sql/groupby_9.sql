with ri as(
    select food_type,max(favorites) as mfv
    from rest_info
    group by food_type
), test as(
    select rr.food_type,rr.rest_id,rr.rest_name,rr.favorites
    from rest_info as rr join ri as rri on rri.mfv=rr.favorites and rri.food_type=rr.food_type
    order by rr.food_type desc
)
select * from test
