-- 코드를 입력하세요
# 들어올땐 중성화 X, 나갈땐 중성화 O
# 동물의 아이디, 생물 종, 이름 조회
# 아이디 순서로 정렬 

SELECT I.Animal_id, i.animal_type, i.name from animal_ins as i
inner join animal_outs as o on o.animal_id = i.animal_id
where i.sex_upon_intake like "Intact%" and SEX_UPON_OUTCOME IN('Neutered Male','Spayed Female')
order by i.animal_id

# -- 코드를 입력하세요 ANIMAL_ID, ANIMAL_TYPE,NAME 
# SELECT A.ANIMAL_ID 
#       ,A.ANIMAL_TYPE
#       ,A.NAME
# FROM ANIMAL_INS AS A
# INNER JOIN (
#            SELECT ANIMAL_ID, SEX_UPON_OUTCOME
#            FROM ANIMAL_OUTS 
#            WHERE SEX_UPON_OUTCOME IN('Neutered Male','Spayed Female')
#             ) AS B ON A.ANIMAL_ID = B.ANIMAL_ID
# WHERE A.SEX_UPON_INTAKE NOT IN ('Neutered Male','Spayed Female')
# ORDER BY 1
