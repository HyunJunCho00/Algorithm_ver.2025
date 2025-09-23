with size as(
    select year(differentiation_date) as y, max(size_of_colony) as max_size
    from ecoli_data
    group by year(differentiation_date)
)
select year(e.differentiation_date) as year, s.max_size-e.size_of_colony as year_dev, e.id
from ecoli_data as e join size as s on s.y=year(e.differentiation_date)
order by year,year_dev;
