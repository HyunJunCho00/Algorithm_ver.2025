with bs as(
    select book_id, sum(sales) as sale
    from book_sales
    where year(sales_date)=2022 and month(sales_date)=1
    group by book_id
), bb as(
    select b.category,b.author_id,sum(b.price*s.sale) as total_prices
    from bs as s join book as b on s.book_id=b.book_id
    group by b.author_id,b.category
)
select a.author_id,a.author_name,b.category,b.total_prices
from bb as b join author as a on a.author_id=b.author_id
order by a.author_id asc,b.category desc;
