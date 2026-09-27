# Write your MySQL query statement below
-- create table newtable as
SELECT machine_id,
       ROUND(AVG(tp2 - tp1), 3) AS processing_time
FROM (
    SELECT t1.machine_id,
           t1.timestamp AS tp1,
           t2.timestamp AS tp2
    FROM Activity AS t1
    INNER JOIN Activity AS t2
        ON t1.machine_id = t2.machine_id
       AND t1.process_id = t2.process_id
       AND t1.activity_type = 'start'
       AND t2.activity_type = 'end'
) AS tablee
GROUP BY machine_id;