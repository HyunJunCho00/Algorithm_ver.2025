with inn as(select animal_id,animal_type,name,sex_upon_intake
from animal_ins
where sex_upon_intake like 'Intact%'
)
select o.animal_id,o.animal_type,o.name
from animal_outs as o join inn on o.animal_id=inn.animal_id
where o.sex_upon_outcome like "Neuter%" or o.sex_upon_outcome like "Spayed%"
order by o.animal_id asc;
