-- 코드를 입력하세요
SELECT  CAR_TYPE, count(CAR_TYPE) as cars FROM CAR_RENTAL_COMPANY_CAR
WHERE OPTIONS Like '%열선시트%' OR OPTIONS Like '%가죽시트%' OR OPTIONS Like '%통풍시트%' 
GROUP BY CAR_TYPE
order by car_type 

