SELECT 
    COALESCE(s2.id, s1.id) AS id,
    s1.student
FROM Seat s1
LEFT JOIN Seat s2
ON (s1.id % 2 = 1 AND s1.id + 1 = s2.id)
   OR (s1.id % 2 = 0 AND s1.id - 1 = s2.id)
ORDER BY id;
