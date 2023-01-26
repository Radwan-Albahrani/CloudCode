SELECT salary * 1.1 AS "Salary with 10% Increase" FROM employee
WHERE ssn IN
(SELECT essn FROM works_on
WHERE pno IN
(SELECT pnumber FROM project WHERE pname LIKE "%ProductX%")
)