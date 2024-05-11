select
    MEMBER_NAME,
    REVIEW_TEXT,
    date_format(REVIEW_DATE,'%Y-%m-%d') as REVIEW_DATE
from
    MEMBER_PROFILE m
join
    REST_REVIEW r
on
    m.MEMBER_ID = r.MEMBER_ID
where
    m.MEMBER_ID = (
        select
            MEMBER_ID
        from
            REST_REVIEW
        group by
            MEMBER_ID
        order by
            count(REVIEW_ID) desc
        limit 1
    )
order by
    r.REVIEW_DATE, REVIEW_TEXT