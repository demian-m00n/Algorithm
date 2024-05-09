select count(*) as COUNT from ECOLI_DATA 
where
    not GENOTYPE & 2 and ( GENOTYPE & 4 or GENOTYPE & 1 )