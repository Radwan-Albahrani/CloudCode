SELECT CONCAT(e.fname, " ", e.minit, ". ", e.lname) as "Name", d.dname as "Department", p.pname as "Project"
FROM employee e
JOIN department d ON e.dno = d.dnumber
JOIN works_on w ON e.ssn = w.essn
JOIN project p ON w.pno = p.pnumber
ORDER BY d.dname, e.lname, e.fname
