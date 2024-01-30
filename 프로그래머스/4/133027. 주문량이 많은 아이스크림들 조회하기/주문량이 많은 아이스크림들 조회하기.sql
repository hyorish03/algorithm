-- 코드를 입력하세요
# 7월 아이스크림 총 주문량 + 상반기 아이스크림 총 주문량이 
# 큰 순서대로 
# 상위 3개의 맛 

Select J.Flavor as Flavor from July as j
Left join first_half as f on j.shipment_id = f.shipment_id
group by j.flavor
order by sum(j.total_order + ifnull(f.total_order, 0)) desc
limit 3;
