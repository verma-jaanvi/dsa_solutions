# Write your MySQL query statement below
SELECT unique_id, name
FROM Employees
LEFT JOIN EmployeeUNI ON Employees.id = EmployeeUNI.id

-- UNION

-- SELECT unique_id, name
-- FROM Employees
-- LEFT JOIN EmployeeUNI ON Employees.id = EmployeeUNI.id;
-- 