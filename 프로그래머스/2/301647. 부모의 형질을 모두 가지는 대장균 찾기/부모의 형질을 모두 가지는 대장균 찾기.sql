select
    ED.ID,
    ED.GENOTYPE,
    ED2.GENOTYPE as PARENT_GENOTYPE
from
    ECOLI_DATA as ED
inner join
    ECOLI_DATA as ED2
on
    ED2.ID = ED.PARENT_ID
where
    ED2.GENOTYPE & ED.GENOTYPE = ED2.GENOTYPE
order by
    ED.ID asc;