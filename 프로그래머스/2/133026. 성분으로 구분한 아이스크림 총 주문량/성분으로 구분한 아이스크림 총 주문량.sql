select
    INGREDIENT_TYPE,
    sum(TOTAL_ORDER) as TOTAL_ORDER
from
    FIRST_HALF h
inner join
    ICECREAM_INFO i
on
    h.FLAVOR = i.FLAVOR
group by
    INGREDIENT_TYPE
order by
    TOTAL_ORDER