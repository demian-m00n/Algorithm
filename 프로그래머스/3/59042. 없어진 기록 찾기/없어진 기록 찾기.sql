select
    o.ANIMAL_ID,
    o.NAME
from
    ANIMAL_OUTS o
left join
    ANIMAL_INS i
on
    i.ANIMAL_ID = o.ANIMAL_ID
where
    INTAKE_CONDITION is null
order by
    ANIMAL_ID, NAME
    