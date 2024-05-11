select
    PRODUCT_CODE,
    sum(SALES_AMOUNT * PRICE) as SALES
from
    PRODUCT p
join
    OFFLINE_SALE s
on
    p.PRODUCT_ID = s.PRODUCT_ID
group by
    PRODUCT_CODE
order by
    SALES desc , PRODUCT_CODE
    