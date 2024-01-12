-- 코드를 입력하세요
# SELECT round(AVG(daily_fee)) as AVERAGE_FEE from car_rental_company_car
# where car_type = '세단'

select round(avg(daily_fee)) AVERAGE_FEE from car_rental_company_car
where car_type = 'suv';