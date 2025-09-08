with hg as(
    select (sum(score)) as score,emp_no
    from hr_grade
    group by emp_no
)
select h.score, he.emp_no, he.emp_name,he.position,he.email
from hr_employees as he join hg as h on
he.emp_no=h.emp_no
order by h.score desc limit 1;
