# Write your MySQL query statement below
select ee.unique_id,e.name from Employees as e
left join EmployeeUNI as ee
on e.id=ee.id
