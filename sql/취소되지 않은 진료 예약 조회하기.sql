with apt as(
    select att.apnt_no, att.apnt_ymd, att.pt_no,att.mddr_id,pt.pt_name
    from appointment as att left join patient as pt on pt.pt_no=att.pt_no
    where date_format(att.apnt_ymd,'%Y-%m-%d') ='2022-04-13' and att.apnt_cncl_yn='N'
)
select ap.apnt_no, ap.pt_name, ap.pt_no,dt.mcdp_cd,dt.dr_name,ap.apnt_ymd
from apt as ap left join doctor as dt on ap.mddr_id=dt.dr_id
order by ap.apnt_ymd asc;
