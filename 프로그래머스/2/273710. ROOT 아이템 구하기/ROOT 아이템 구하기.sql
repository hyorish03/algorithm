-- 코드를 작성해주세요-- 코드를 작성해주세요
# ROOT 아이템을 찾아 id, name을 출력
SELECT i.item_id, i.item_name from item_info as i inner join item_tree as t on t.item_id = i.item_id
where t.parent_item_id is null