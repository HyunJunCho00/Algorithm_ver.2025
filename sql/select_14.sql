with ed as(
    select id,size_of_colony,NTILE(4) over (order by size_of_colony desc) as quantile
    from ecoli_data
)
select id, case when quantile = 1 then "CRITICAL"
            when quantile = 2 then "HIGH"
            when quantile = 3 then "MEDIUM"
            else "LOW" 
            end as colony_name
from ed
order by id asc;
