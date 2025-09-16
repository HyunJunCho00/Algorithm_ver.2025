with hg as(
    select emp_no,avg(score) as score
    from hr_grade
    group by emp_no
), he as(
    select e.emp_no,e.emp_name,case when g.score>=96 then 'S'
                                when g.score>=90 then 'A'
                                when g.score>=80 then 'B'
                                else 'C' end as grade
    from hr_employees as e join hg as g on g.emp_no=e.emp_no
), bo as(
    select g.emp_no,case when g.score>=96 then e.sal*0.2
                                when g.score>=90 then e.sal*0.15
                                when g.score>=80 then e.sal*0.1
                                else 0 end as bonus
    from hg as g join hr_employees as e on e.emp_no=g.emp_no
)
select e.emp_no,e.emp_name,e.grade,b.bonus
from he as e join bo as b on b.emp_no=e.emp_no
order by e.emp_no asc;
