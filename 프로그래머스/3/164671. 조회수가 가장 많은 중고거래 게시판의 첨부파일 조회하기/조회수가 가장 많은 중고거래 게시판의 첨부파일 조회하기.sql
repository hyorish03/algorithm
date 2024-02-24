-- 코드를입력하세요
# 조회수가 가장 높은
# 첨부파일 경로 조회
# FileId 기준 낼미차순
# /home/grep/src/boardID/file_id+fileId+FileEXT
# SELECT concat('/hom/grep/src/', b.board_id, '/', f.file_id,f.file_name, f.file_ext) as file_path from USED_GOODS_BOARD as b inner join USED_GOODS_FILE as f on f.board_id = b.board_id
# AND VIEWS = (SELECT MAX(VIEWS) 
#              FROM USED_GOODS_BOARD)
# order by f.file_id desc

SELECT CONCAT("/","home/grep/src","/",b.BOARD_ID,"/",FILE_ID,FILE_NAME, FILE_EXT)FILE_PATH
FROM USED_GOODS_BOARD as b, USED_GOODS_FILE as f
WHERE b.BOARD_ID = f.BOARD_ID
AND VIEWS = (SELECT MAX(VIEWS) 
             FROM USED_GOODS_BOARD)
order by FILE_ID desc
