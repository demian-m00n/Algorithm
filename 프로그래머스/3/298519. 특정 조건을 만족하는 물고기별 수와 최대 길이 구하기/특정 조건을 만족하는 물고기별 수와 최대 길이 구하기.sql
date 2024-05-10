select
    count(*) as FISH_COUNT,
    max(LENGTH) as MAX_LENGTH,
    FISH_TYPE
from
    (select
        FISH_TYPE,
        coalesce(LENGTH,10) as LENGTH
    from
        FISH_INFO) a
group by
    FISH_TYPE
having
    avg(LENGTH) >= 33
order by
    FISH_TYPE