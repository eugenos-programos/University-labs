-- 11. Get all pairs of city names for which the supplier from the first city provides a project in the second city.
SELECT DISTINCT suppliers_p.city, project_g.city
FROM spj
INNER JOIN suppliers_p USING(p)
INNER JOIN project_g USING(pr)

-- 32. Get the project numbers provided by at least all the details of the supplier P1.
SELECT pr
FROM spj
GROUP BY pr, p
HAVING COUNT(DISTINCT d) = (
SELECT COUNT(DISTINCT d)
  FROM spj
  WHERE p = 'П1') AND p = 'П1'

-- 4. Get all shipments where the quantity is in the range from 300 to 750 inclusive.
SELECT *
FROM spj
WHERE S BETWEEN 300 AND 750

-- 7. Get all such triples "supplier numbers-part numbers-project numbers" for which the output supplier, part and project are not located in the same city.
SELECT p, d, pr
FROM spj
INNER JOIN details_p USING(d)
INNER JOIN project_g USING(pr)
INNER JOIN suppliers_p USING(p)
WHERE suppliers_p.city != project_g.city OR
      suppliers_p.city != details_p.city OR
      details_p.city != project_g.city
      
-- 16. Get the total number of details D1 supplied by supplier P1.
SELECt SUM(s)
FROM spj
WHERE p = 'П1'

-- 31. Get the numbers of suppliers supplying the same part for all projects.
SELECt s
FROM spj
WHERE d = (
SELECt d
FROM spj
GROUP BY d
HAVING COUNT(DISTINCT pr) = (
  SELECT COUNT(pr)
  FROM project_g
))

-- 26. Get the project numbers for which the average number of supplied parts D1 is greater than the largest number of any parts supplied for the PR1 project.
SELECT pr
FROM spj
WHERE d = 'Д1'
GROUP BY pr
HAVING AVG(s) > (
  SELECT MAX(s)
  FROM spj 
  WHERE pr = 'ПР1'
)

-- 22. Get project numbers using at least one part available from supplier P1.
SELECT DISTINCT pr
FROM spj
WHERE d IN (
  SELEcT d
  FROM spj
  WHERE p = 'П1'
)

-- 8. Get all such triples "supplier numbers-part numbers-project numbers" for which none of the two output suppliers, parts and projects are located in the same city.
SELECT p, d, pr
FROM spj
INNER JOIN details_p USING(d)
INNER JOIN project_g USING(pr)
INNER JOIN suppliers_p USING(p)
WHERE suppliers_p.city != project_g.city AND
      suppliers_p.city != details_p.city AND
      details_p.city != project_g.city

-- 28. Get project numbers for which red parts are not supplied by suppliers from London.
SELECT DISTINCT pr
FROM spj
INNER JOIN suppliers_p USING(p)
INNER JOIN details_p USING(d)
WHERE details_p.color != 'Красный' AND
      suppliers_p.city != 'Таллинн'

      
