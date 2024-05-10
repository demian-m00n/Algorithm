select
    CATEGORY,
    sum(SALES) as TOTAL_SALES
from
    BOOK b
inner join
    BOOK_SALES s
on
    b.BOOK_ID = s.BOOK_ID
where
    DATE_FORMAT(SALES_DATE,'%Y-%m') = '2022-01'
group by
    CATEGORY
order by
    CATEGORY