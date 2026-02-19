SELECT animal_id, name
from animal_ins
where animal_type = "Dog" and name REGEXP 'el' 
order by name;
