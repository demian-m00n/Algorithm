with COL as
(
    select
        YEAR,
        max(SIZE_OF_COLONY) as SOC
    from
        ECOLI_DATA ed
    inner join
        (
            select
                ID,
                YEAR(DIFFERENTIATION_DATE) as YEAR
            from
                ECOLI_DATA            
        ) as ey
    on
        ed.ID = ey.ID
    group by
        YEAR
)

select
    COL.YEAR,
    COL.SOC - ed.SIZE_OF_COLONY as YEAR_DEV,
    ed.ID
from
    ECOLI_DATA ed
inner join
    COL
on
    YEAR(ed.DIFFERENTIATION_DATE) = COL.YEAR
order by
    YEAR asc, YEAR_DEV