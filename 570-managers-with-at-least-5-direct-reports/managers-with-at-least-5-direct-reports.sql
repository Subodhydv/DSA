Select e.name from employee e inner  join employee e2 
on e.id=e2.managerID group by e.id having count(e2.id)>=5;