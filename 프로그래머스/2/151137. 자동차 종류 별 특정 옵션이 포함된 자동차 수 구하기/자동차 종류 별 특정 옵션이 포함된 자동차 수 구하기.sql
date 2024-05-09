select
    CAR_TYPE,
    COUNT(*) as CARS
from
    CAR_RENTAL_COMPANY_CAR c
where
    OPTIONS LIKE '%통풍시트%' or
    OPTIONS LIKE '%열선시트%' or
    OPTIONS LIKE '%가죽시트%'
group by
    CAR_TYPE
order by
    CAR_TYPE