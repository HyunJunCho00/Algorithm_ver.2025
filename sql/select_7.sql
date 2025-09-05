with rr as(
    select rest_id,round(avg(review_score),2) as score
    from rest_review
    group by rest_id
)
select ri.rest_id,ri.rest_name,ri.food_type,ri.favorites,ri.address,rrr.score
from rest_info as ri join rr as rrr on rrr.rest_id=ri.rest_id
where ri.address like "서울%"
order by rrr.score desc, ri.favorites desc;
