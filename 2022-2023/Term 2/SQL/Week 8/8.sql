SELECT DISTINCT concat(E.fname, " ", E.lname) as "Employee name",
concat(M.fname , " " , M.lname) as "Manager name"
FROM employee as E, Employee as M
Where E.superssn = M.ssn