select e.id,e.genotype,ee.genotype as parent_genotype
from ecoli_data as e left join ecoli_data as ee on e.parent_id=ee.id
where ee.genotype&e.genotype =ee.genotype
order by e.id
