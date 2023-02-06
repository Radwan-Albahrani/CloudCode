SELECT ExperienceLevel, SUM(HoursWorked) AS TotalHoursWorked
FROM EMPLOYEE
JOIN PROPERTY_SERVICE ON EMPLOYEE.EmployeeID = PROPERTY_SERVICE.EmployeeID
GROUP BY ExperienceLevel
ORDER BY TotalHoursWorked DESC;