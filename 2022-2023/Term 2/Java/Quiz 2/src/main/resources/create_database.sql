DROP DATABASE IF EXISTS Company;
CREATE DATABASE Company;
Use Company;

CREATE TABLE EMPLOYEE(
    Employee_ID int not null primary KEY,
    name VARCHAR(255) not null,
    salary int not null
);

INSERT INTO Employee VALUES
(100, "Fadi", 4000),
(200, "hdi", 5000);

DROP USER IF EXISTS "javaQuiz@localhost";
CREATE USER 'JavaQuiz'@'localhost' IDENTIFIED WITH mysql_native_password BY 'root';
GRANT ALL PRIVILEGES ON *.* TO 'JavaQuiz'@'localhost' WITH GRANT OPTION;