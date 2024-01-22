-- 코드를 입력하세요
SELECT floor(price/10000) * 10000 as prices, count(*)
from product
group by prices
order by prices