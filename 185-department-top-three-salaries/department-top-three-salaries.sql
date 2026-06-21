# Write your MySQL query statement below
WITH CTE AS
(
    SELECT
        name,
        salary,
        departmentId,
        DENSE_RANK() OVER(
            PARTITION BY departmentId
            ORDER BY salary DESC
        ) AS rnk
    FROM Employee
)

SELECT
    d.name AS Department,
    c.name AS Employee,
    c.salary AS Salary
FROM CTE c
JOIN Department d
ON c.departmentId = d.id
WHERE c.rnk <= 3;