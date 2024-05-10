select
    d.DEPT_ID,
    d.DEPT_NAME_EN,
    round(avg(e.SAL)) as AVG_SAL
from
    HR_DEPARTMENT d
inner join
    HR_EMPLOYEES e
on
    d.DEPT_ID = e.DEPT_ID
group by
    d.DEPT_ID
order by
    AVG_SAL desc