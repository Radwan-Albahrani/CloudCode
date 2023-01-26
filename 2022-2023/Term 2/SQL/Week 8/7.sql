SELECT DISTINCT CONCAT(fname, " ", minit, ". ", lname) as "Name"
FROM Employee
JOIN department ON employee.ssn = department.mgrssn
WHERE (SELECT COUNT(dependent_name) FROM dependent WHERE essn = employee.ssn) >= 1