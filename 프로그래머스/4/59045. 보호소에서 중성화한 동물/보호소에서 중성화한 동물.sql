-- 코드를 입력하세요
# 들어올땐 중성화 X, 나갈땐 중성화 O
# 동물의 아이디, 생물 종, 이름 조회
# 아이디 순서로 정렬 

SELECT I.Animal_id, i.animal_type, i.name from animal_ins as i
inner join animal_outs as o on o.animal_id = i.animal_id
where i.sex_upon_intake != o.sex_upon_outcome 
order by i.animal_id