-- 코드를 입력하세요
SELECT  I.animal_id, i.name from animal_ins as i
inner join animal_outs as o 
on o.animal_id = i.animal_id
where I.dateTime > o.dateTime
order by I.dateTime asc