select
    hour(DATETIME) as HOUR,
    count(*) as COUNT
from
    ANIMAL_OUTS
where
    DATE_FORMAT(DATETIME,'%H') >= 9 and
    DATE_FORMAT(DATETIME,'%H') < 20
group by
    hour(DATETIME)
order by
    HOUR