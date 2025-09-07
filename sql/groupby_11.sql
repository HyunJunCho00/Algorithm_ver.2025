SELECT year(os.sales_date) as YEAR, month(os.sales_date) as MONTH,ui.gender, count(distinct ui.user_id) as USERS
from online_sale as os left join user_info as ui on 
os.user_id=ui.user_id
group by year(os.sales_date), month(os.sales_date), ui.gender
having ui.gender is not NULL
order by YEAR,MONTH,GENDER;
