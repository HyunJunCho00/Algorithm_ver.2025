with d as(
    select distinct id,email,first_name,last_name
    from developers join skillcodes as s on s.code&skill_code>0 and category like "Front End"
    order by id asc
)
select * from d
