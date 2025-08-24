-- 코드를 입력하세요
SELECT b.animal_id as animal_id, b.name as name
from animal_outs as b
where not exists(select * from animal_ins as a where b.animal_id=a.animal_id)
order by b.animal_id asc;
