-- 코드를 입력하세요
SELECT b.book_id, A.author_name, date_format(b.published_date,"%Y-%m-%d")  from author as a 
inner join book as b on b.Author_id = a.Author_id
where b.category = "경제"
order by b.published_date 