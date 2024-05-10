with HR_SCORE as
(
    select
        EMP_NO,
        sum(SCORE) as SCORE
    from
        HR_GRADE
    where
        YEAR = 2022
    group by
        EMP_NO
    order by
        SCORE desc
    limit 1
)

select
    s.SCORE,
    h.EMP_NO,
    h.EMP_NAME,
    h.POSITION,
    h.EMAIL
from
    HR_EMPLOYEES h
inner join
    HR_SCORE s
on
    h.EMP_NO = s.EMP_NO