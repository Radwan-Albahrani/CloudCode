SELECT pnumber as "Project Number", dep.dnumber as "Department Number", 
lname as "Manager Last Name", address, bdate, "Birth Date"
FROM project, dept_locations as deploc, department as dep, employee
WHERE dlocation = "Stafford"
AND dep.mgrssn = employee.ssn
AND dep.dnumber = deploc.dnumber
AND dep.dnumber = project.dnum;