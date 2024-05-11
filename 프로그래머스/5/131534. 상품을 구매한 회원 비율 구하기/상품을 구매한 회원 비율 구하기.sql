select
    YEAR(SALES_DATE) as YEAR,
    MONTH(SALES_DATE) as MONTH,
    count(distinct(i.USER_ID)) as PUCHASED_USERS,
    round(count(distinct(i.USER_ID)) / (SELECT
                                COUNT(*)
                            FROM
                                USER_INFO
                            WHERE
                                year(JOINED) = 2021),1) as PUCHASED_RATIO
from
    USER_INFO i
join
    ONLINE_SALE s
on
    i.USER_ID = s.USER_ID
where
    year(JOINED) = 2021
group by
    YEAR(SALES_DATE),MONTH(SALES_DATE)
order by
    YEAR(SALES_DATE),MONTH(SALES_DATE)
