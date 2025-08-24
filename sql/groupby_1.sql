select hour(datetime) as HOUR, count(animal_id) as COUNT
from animal_outs
group by hour(datetime)
having HOUR >=9 and HOUR<20
order by HOUR ASC;
