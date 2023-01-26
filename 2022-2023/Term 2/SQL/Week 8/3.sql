SELECT DISTINCT CONCAT(fname, " ", minit, ". ", lname) as "Name"
FROM employee
JOIN works_on ON works_on.essn = employee.ssn
JOIN project ON works_on.pno = project.pnumber
WHERE project.dnum = 5
GROUP BY employee.ssn
HAVING COUNT(DISTINCT project.pnumber) =
(SELECT COUNT(DISTINCT pnumber) FROM project WHERE dnum = 5)
