-- 코드를 입력하세요
# 입양 못 간 동물 중, 가장 오래 보호소에 있던 동물 3마리의 이름, 보호 시작일을 조회
# 보호 시작을 기준 내림차순
Select i.Name as name, i.datetime as datetime from animal_ins as i
left join animal_outs as o
on o.animal_id = i.animal_id
where o.animal_id is null
order by datetime asc
limit 3;