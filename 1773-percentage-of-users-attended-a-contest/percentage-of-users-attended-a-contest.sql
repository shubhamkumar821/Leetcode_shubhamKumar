# Write your MySQL query statement below

select R.contest_id, round ( count(R.contest_id)*100.0/ (select count(*) from Users) ,2) as percentage 
from Register as R
group by  contest_id 
order by percentage desc,R.contest_id;
