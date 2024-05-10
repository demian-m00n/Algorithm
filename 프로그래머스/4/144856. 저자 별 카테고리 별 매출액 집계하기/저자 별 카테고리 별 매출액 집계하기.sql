select
    b.AUTHOR_ID,
    a.AUTHOR_NAME,
    b.CATEGORY,
    sum(SALES * PRICE) as TOTAL_SALES
from
    (BOOK b
inner join
    AUTHOR a
on
    b.AUTHOR_ID = a.AUTHOR_ID)
inner join
    BOOK_SALES s
on
    b.BOOK_ID = s.BOOK_ID
where
    DATE_FORMAT(SALES_DATE,'%Y-%m') = '2022-01'
group by
    AUTHOR_ID, CATEGORY
order by
    AUTHOR_ID, CATEGORY desc