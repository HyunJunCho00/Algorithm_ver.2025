with ed as(
    select e.id
    from ecoli_data as e join ecoli_data as d on d.id=e.parent_id and d.parent_id is null
), res as(
    select distinct(a.id)
    from ecoli_data as a join ed as e on e.id=a.parent_id 
    order by a.id asc
)
select * from res
