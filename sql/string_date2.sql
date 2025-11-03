with u as(
    select board_id
    from used_goods_board
    order by views desc limit 1
)

select concat("/home/grep/src/",ugf.board_id,"/",ugf.file_id,file_name,ugf.file_ext) as file_path
from used_goods_file as ugf join u as uu on uu.board_id=ugf.board_id
order by ugf.file_id desc;
