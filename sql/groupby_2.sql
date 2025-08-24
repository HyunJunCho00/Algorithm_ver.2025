with recursive hours as(
    select 0 as hour
    union all
    select hour+1
    from hours
    where hour<23
)
select h.hour as HOUR, count(a.animal_id) as COUNT
from hours as h left join animal_outs as a on h.hour=hour(a.datetime)
group by HOUR
order by HOUR ASC;
