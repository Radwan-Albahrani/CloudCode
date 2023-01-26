SELECT DISTINCT CONCAT(fname, " ", minit, ". ", lname) as "Name"
FROM Employee
WHERE (SELECT COUNT(dependent_name) FROM dependent WHERE essn = employee.ssn) = 