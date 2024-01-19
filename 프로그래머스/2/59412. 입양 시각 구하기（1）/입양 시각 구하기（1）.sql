SELECT HOUR(DATETIME) as hour, COUNT(*) as count FROM ANIMAL_OUTS 
group by hour
having hour >= 9 and hour < 20
order by hour