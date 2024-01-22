-- 코드를 입력하세요
SELECT 
case 
when Price < 10000  then 0 
when Price < 20000  then 10000
when Price < 30000  then 20000
when Price < 40000  then 30000
when Price < 50000  then 40000
when Price < 60000  then 50000
when Price < 70000  then 60000
when Price < 80000  then 70000
when Price < 90000  then 80000
when Price < 100000  then 90000
else 0
end as prices, count(*)
from product
group by prices
order by prices