# Write your MySQL query statement bel
select customer_number
from Orders
group by customer_number 
order by count(order_number) DESC
LIMIT 1;