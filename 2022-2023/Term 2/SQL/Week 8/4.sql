SELECT DISTINCT project.pnumber as "Project Number"
FROM project
JOIN department ON project.dnum = department.dnumber
JOIN employee ON department.mgrssn = employee.ssn
OR employee.ssn IN
(SELECT essn FROM works_on WHERE works_on.pno = project.pnumber)
WHERE employee.lname = 'Smith';