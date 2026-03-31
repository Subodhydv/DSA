select e.name from 
Employee as e
join Employee m
on e.id=m.managerId
group by e.id, m.managerId
having count(m.id)>=5;