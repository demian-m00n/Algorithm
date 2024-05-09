with ANS as
(
    select
        WRITER_ID,
        sum(PRICE) as TOTAL_SALES
    from
        USED_GOODS_BOARD
    where
        STATUS = 'DONE'
    group by
        WRITER_ID
)

select
    UGU.USER_ID,
    UGU.NICKNAME,
    ANS.TOTAL_SALES
from
    USED_GOODS_USER UGU
inner join
    ANS
on
    UGU.USER_ID = ANS.WRITER_ID
where
    ANS.TOTAL_SALES >= 700000
order by
    ANS.TOTAL_SALES