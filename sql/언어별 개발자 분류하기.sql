select case when skill_code & (select sum(code) from skillcodes where category regexp "Front")>0 and skill_code & (select sum(code) from skillcodes where name REGEXP "Python")>0 then "A" when skill_code & (select sum(code) from skillcodes where name  REGEXP "C#")>0 then "B" when skill_code & (select sum(code) from skillcodes where category regexp "Front")>0 then "C" else NULL end as grade,id,email
from developers
having grade is not null
order by grade ,id;
