SELECT e.ssn, d.dname
FROM employee e
JOIN department d ON e.dno = d.dnumber