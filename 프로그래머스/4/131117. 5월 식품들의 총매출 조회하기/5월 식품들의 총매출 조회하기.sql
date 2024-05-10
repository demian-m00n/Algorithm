select
    o.PRODUCT_ID,
    p.PRODUCT_NAME,
    sum(o.AMOUNT * p.PRICE) as TOTAL_SALES
from
    FOOD_ORDER o
join
    FOOD_PRODUCT p
on
    o.PRODUCT_ID = p.PRODUCT_ID
where
    date_format(PRODUCE_DATE,'%Y-%m') = '2022-05'
group by
    PRODUCT_ID
order by
    TOTAL_SALES desc, PRODUCT_ID