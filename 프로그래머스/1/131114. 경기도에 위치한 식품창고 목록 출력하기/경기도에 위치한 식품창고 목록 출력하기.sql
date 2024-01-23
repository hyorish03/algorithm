-- 코드를 입력하세요
SELECT WAREHOUSE_ID, WAREHOUSE_NAME, ADDRESS, ( case when FREEZER_YN is null then "N" when FREEZER_YN = "N" then "N" else "Y" end ) as freezer from FOOD_WAREHOUSE 
where ADDRESS like "경기도%"