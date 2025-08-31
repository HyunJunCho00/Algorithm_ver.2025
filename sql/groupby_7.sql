with fi as(
    select count(*) as fish_count, max(length) as max_length, fish_type
    from fish_info
    group by fish_type
    having avg(greatest(coalesce(length,0),10))>=33
    order by fish_type asc
)
select *
from fi
