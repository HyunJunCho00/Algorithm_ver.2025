SELECT ii.ingredient_type ,sum(fh.total_order) as total_order
from first_half as fh,icecream_info as ii
where fh.flavor=ii.flavor
group by ii.ingredient_type
order by total_order asc;
