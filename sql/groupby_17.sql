select route,CONCAT(round(sum(d_between_dist),1), 'km') as total_distance, CONCAT(round(avg(d_between_dist),2), 'km') as average_distance
from subway_distance
group by route
order by sum(d_between_dist) desc;
