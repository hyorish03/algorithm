SELECT CAR_ID,MAX(
       CASE
           WHEN '2022-10-16' > C.END_DATE THEN '대여 가능'
           WHEN C.START_DATE > '2022-10-16' THEN '대여 가능'
           ELSE '대여중'
       END) AS AVAILABILITY
        
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY AS C
group by car_id
order by car_id desc;

-- 코드를 입력하세요
-- 2022년 10월 16일에 대여 중인 자동차인 경우 '대여중' 이라고 표시
-- 대여 중이지 않은 자동차인 경우 '대여 가능'을 표시
-- 이때 반납 날짜가 2022년 10월 16일인 경우에도 '대여중'으로 표시
-- 자동차 ID를 기준으로 내림차순 정렬.
# SELECT 
#     CAR_ID,
#     MAX(
#         CASE WHEN 
#         '2022-10-16' BETWEEN DATE_FORMAT(START_DATE, '%Y-%m-%d') AND DATE_FORMAT(END_DATE, '%Y-%m-%d') 
#         THEN '대여중'
#         ELSE '대여 가능'
#         END
#     ) AS AVAILABILITY 
# FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY 
# GROUP BY CAR_ID
# ORDER BY 1 DESC