# Write your MySQL query statement below

select id as Id 
from(
select t2.id,t1.temperature as tp1, t2.temperature as tp2 from Weather as t1
Left JOIN Weather as t2 on datediff(t2.recordDate,t1.recordDate)=1
) as newt
where tp2>tp1;

