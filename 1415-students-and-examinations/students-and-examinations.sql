# Write your MySQL query statement below
select t2.student_id, t2.student_name, t2.subject_name, COALESCE(t1.attended_exams, 0) as attended_exams
from
(
select student_id, count(subject_name) as attended_exams ,subject_name
from Examinations
group by student_id, subject_name
)
as t1

right join 

(
select distinct student_id,student_name, subject_name
from Students
cross join Subjects
) as t2

on t1.student_id = t2.student_id
and t1.subject_name=t2.subject_name
order by t2.student_id , t2.subject_name;
