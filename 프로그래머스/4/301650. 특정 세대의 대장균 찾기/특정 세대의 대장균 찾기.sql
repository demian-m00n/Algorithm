with recursive ECOLI_GEN as
(
    select
        ID,
        PARENT_ID,
        1 as GENERATION
    from
        ECOLI_DATA
    where
        PARENT_ID is null
    union all
    (
        select
            ED.ID,
            ED.PARENT_ID,
            EG.GENERATION + 1 as GENERATION
        from
            ECOLI_DATA as ED
        inner join
            ECOLI_GEN as EG
        on ED.PARENT_ID = EG.ID
    )
)

select 
    ID
from
    ECOLI_GEN EG
where
    EG.GENERATION = 3
order by
    ID asc;