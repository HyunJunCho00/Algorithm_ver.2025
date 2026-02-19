select id,email,first_name,last_name
from developers 
where skill_code & (select sum(code) from skillcodes where name = "C#" or name = "Python") >0
order by id;
