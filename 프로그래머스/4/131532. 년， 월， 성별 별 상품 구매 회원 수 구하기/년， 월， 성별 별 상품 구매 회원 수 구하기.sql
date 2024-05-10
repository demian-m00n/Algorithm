select
    YEAR(SALES_DATE) as YEAR,
    MONTH(SALES_DATE) as MONTH,
    GENDER,
    count(distinct(o.USER_ID)) as USERS
from
    ONLINE_SALE o
join
    USER_INFO u
on
    o.USER_ID = u.USER_ID
where
    GENDER is not null
group by
    YEAR(SALES_DATE),MONTH(SALES_DATE),GENDER
order by
    YEAR(SALES_DATE),MONTH(SALES_DATE),GENDER