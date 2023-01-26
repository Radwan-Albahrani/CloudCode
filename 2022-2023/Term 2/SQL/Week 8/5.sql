SELECT DISTINCT CONCAT(fname, " ", minit, ". ", lname) as "Name"
FROM Employee
JOIN dependent ON (employee.ssn = dependent.essn)
WHERE (SELECT COUNT(dependent_name) FROM dependent WHERE essn = employee.ssn) >= 2