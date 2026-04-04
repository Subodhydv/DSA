 SELECT MAX(num) AS num
FROM (select num
from mynumbers
group by num
HAVING COUNT(*) = 1)
as t;