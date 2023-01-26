SELECT *
FROM Employee
JOIN department on Employee.dno = department.dnumber
WHERE department.dnum = 5
AND employee.salary >= 30000
AND employee.salary <= 40000