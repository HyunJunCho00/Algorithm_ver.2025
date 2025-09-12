with fish as(
    select fish_type ,max(length) as length
    from fish_info
    group by fish_type
), f as(
    select ff.id, f.fish_type,f.length
    from fish_info as ff join fish as f on
    f.fish_type=ff.fish_type and f.length=ff.length
)
select id, fish_name, length
from f as f1 join fish_name_info as fn on
fn.fish_type=f1.fish_type
order by id asc;
