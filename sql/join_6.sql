select ai.name, ai.datetime
from animal_ins as ai
where ai.name not in(select ao.name
                  from animal_outs ao
                  where ao.animal_id=ai.animal_id)
order by ai.datetime asc limit 3
