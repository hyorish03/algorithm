select pt_name, pt_no, gend_cd, age, ifnull(tlno, 'NONE') as tlno from patient
where gend_cd = 'w' and age <= 12
order by age desc ,pt_name asc;