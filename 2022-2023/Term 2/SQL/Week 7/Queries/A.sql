-- Retrieve the names of employees in department 5 who work more than 10 hours 
-- per week on the 'ProductX' project
SELECT fname,
    lname
FROM employee
WHERE dno = 5
    AND ssn IN (
        SELECT essn
        FROM works_on
        WHERE pno = (
                SELECT pnumber
                FROM project
                WHERE pname = 'ProductX'
            )
            AND hours > 10
    );