with PER as
(
    select
        ID,
        NTILE(4) OVER (order by SIZE_OF_COLONY desc) as SG
    from
        ECOLI_DATA
),
COL as
(
    select
        ID,
        case
            when SG = 1 then 'CRITICAL'
            when SG = 2 then 'HIGH'
            when SG = 3 then 'MEDIUM'
            else 'LOW'
        end as NAME
    from
        PER
)

select
    ED.ID,
    COL.NAME as COLONY_NAME
from
    ECOLI_DATA ED
inner join
    COL
on
    ED.ID = COL.ID
order by
    ED.ID asc;
