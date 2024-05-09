with recursive GEN as
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
            GEN.GENERATION + 1 as GENARTION
        from
            ECOLI_DATA ED
        inner join
            GEN
        on
            GEN.ID = ED.PARENT_ID
    )
)

select
    COUNT(ID) as COUNT,
    GENERATION
from
    GEN
where
    ID not in
    (
        select
            distinct PARENT_ID
        from
            ECOLI_DATA
        where
            PARENT_ID is not null
    )
group by
    GENERATION
order by
    GENERATION