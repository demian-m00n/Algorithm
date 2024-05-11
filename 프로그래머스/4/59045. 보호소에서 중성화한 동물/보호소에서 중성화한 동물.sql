select
    o.ANIMAL_ID,
    o.ANIMAL_TYPE,
    o.NAME
from
    ANIMAL_INS i
join
    ANIMAL_OUTS o
on
    i.ANIMAL_ID = o.ANIMAL_ID
where
    SEX_UPON_INTAKE != SEX_UPON_OUTCOME