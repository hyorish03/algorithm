-- 코드를 입력하세요
# SELECT O.animal_id, O.name from animal_ins as i
# right join animal_outs as o
# on o.animal_id = i.animal_id
# where i.animal_id is null
# order by i.animal_id, i.name

select o.animal_id as id, o.name as name from animal_ins as i
right join animal_outs as o
on o.animal_id = i.animal_id
where i.animal_id is null
order by i.animal_id, i.name