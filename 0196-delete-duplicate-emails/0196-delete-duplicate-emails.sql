# Write your MySQL query statement below
DELETE p1
FROM Person p1
INNER JOIN Person p2
ON p1.Email = p2.Email AND p1.Id > p2.Id;
