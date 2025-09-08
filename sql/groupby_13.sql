with hh as(
    select dept_id, round(avg(sal),0) as avg_sal
    from HR_EMPLOYEES
    group by dept_id
)
select h.dept_id,hd.dept_name_en,h.avg_sal
from hr_department as hd join hh as h on
h.dept_id=hd.dept_id
order by h.avg_sal desc;
