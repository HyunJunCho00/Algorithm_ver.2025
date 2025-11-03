select item_id,item_name,rarity
from item_info
where item_id not in (
    select parent_item_id
    from item_tree
    where PARENT_ITEM_ID is not null
)
order by item_id desc;
