select os.user_id,os.product_id
from online_sale as os
group by os.user_id,os.product_id
having count(*)>=2
order by user_id asc, product_id desc;
