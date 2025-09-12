select count(A.fish_type) as fish_count, A.fish_name
from fish_name_info as A join fish_info as B on
A.fish_type=B.fish_type
group by A.fish_type,A.fish_name
order by fish_count desc;
# WITH ff AS (
#     SELECT fish_type, COUNT(*) AS FISH_COUNT
#     FROM fish_info
#     GROUP BY fish_type
# )
# SELECT f.FISH_COUNT, fn.FISH_NAME
# FROM fish_name_info AS fn
# JOIN ff AS f
# ON f.fish_type = fn.fish_type
# ORDER BY f.FISH_COUNT DESC;
