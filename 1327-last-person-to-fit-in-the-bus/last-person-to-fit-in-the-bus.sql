# Write your MySQL query statement below
SELECT person_name 
from(
    select person_name,
    sum( weight) over (order by turn) as Total_weight
    from Queue 
    ) as t
    where Total_weight <=1000
    order by Total_weight DESC
    Limit 1;