-- 코드를 입력하세요
SELECT b.TITLE, b.Board_id, r.reply_id,  r.writer_id, r.contents, date_format(r.created_date, "%Y-%m-%d") as CREATED_DATE from used_goods_board as b inner join used_goods_reply as r on b.board_id = r.board_id
WHERE B.CREATED_DATE LIKE "2022-10%"
ORDER BY R.CREATED_DATE asc, B.TITLE asc


