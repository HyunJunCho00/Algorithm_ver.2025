with fh as(
select flavor,sum(total_order) as fh_total
    from first_half
    group by flavor
), j as(
select flavor, sum(total_order)as j_total
    from july
    group by flavor
)

select fh.flavor
from fh join j on fh.flavor=j.flavor
order by (fh.fh_total+j.j_total) desc limit 3;
