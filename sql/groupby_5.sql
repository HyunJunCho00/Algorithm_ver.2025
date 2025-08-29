with ugb as(
    select writer_id,sum(price) as price
    from used_goods_board
    where status='DONE'
    group by writer_id
    ),ugu as(
    select user_id,nickname,ugb.price as total_sales
    from used_goods_user join ugb on user_id=ugb.writer_id
    where ugb.price>=700000
    order by total_sales asc
)
select *
from ugu
