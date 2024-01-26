-- 코드를 입력하세요
SELECT Product_code as pc, sum(P.price * O.sales_amount) as sales from Product as p
inner join Offline_sale as o on o.product_id = p.product_id
group by pc
order by sales desc, pc asc