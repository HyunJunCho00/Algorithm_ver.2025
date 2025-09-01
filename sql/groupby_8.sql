with bk as(
    select book_id,sum(sales) as sale
    from book_sales
    where month(sales_date)=1 and year(sales_date)=2022
    group by book_id
)
select category, sum(sale) as total_sales
from book as b left join bk as k on b.book_id=k.book_id
group by category
order by category asc;
