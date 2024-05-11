with FE as
(
    select
        sum(CODE) as CODE
    from
        SKILLCODES
    where
        CATEGORY = 'Front End'
    group by
        CATEGORY
)

select
    ID,
    EMAIL,
    FIRST_NAME,
    LAST_NAME
from
    DEVELOPERS d
join
    FE f
on
    d.SKILL_CODE & f.CODE
order by
    ID