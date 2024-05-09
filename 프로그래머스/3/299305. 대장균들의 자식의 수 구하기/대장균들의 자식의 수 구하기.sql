select ID, (select count(*) from ECOLI_DATA where ED.ID = PARENT_ID) as CHILD_COUNT
from 
    ECOLI_DATA as ED
order by
    ID;
    