SELECT CONCAT(Fname, " ", Minit, " ", Lname) AS "Name", address
FROM EMPLOYEE as E, department as D
WHERE E.dno = D.dnumber AND D.dname = "Research";