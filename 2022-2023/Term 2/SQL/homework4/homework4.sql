CREATE TABLE IF NOT EXISTS DEPARTMENT(
    DName VARCHAR(50) NOT NULL,
    DNumber INT NOT NULL PRIMARY KEY,
    Mgr_SSN INT NOT NULL,
    Mgr_Start_Date DATE NOT NULL
);
CREATE TABLE IF NOT EXISTS EMPLOYEEE(
    Fname VARCHAR(50) NOT NULL,
    MName VARCHAR(50) NOT NULL,
    LName VARCHAR(50) NOT NULL,
    SSN INT NOT NULL PRIMARY KEY,
    BDate DATE NOT NULL,
    Address VARCHAR(50) NOT NULL,
    SEX ENUM("M", "F") NOT NULL,
    Salary INT NOT NULL,
    Super_SSN INT NOT NULL,
    DNO INT NOT NULL,
    FOREIGN KEY (Super_SSN) REFERENCES EMPLOYEEE(SSN),
    FOREIGN KEY (DNO) REFERENCES DEPARTMENT(DNumber)
);
CREATE TABLE IF NOT EXISTS PROJECT(
    PName VARCHAR(50) NOT NULL,
    PNumber INT NOT NULL PRIMARY KEY,
    PLocation VARCHAR(50) NOT NULL,
    DNum INT NOT NULL,
    FOREIGN KEY (DNum) REFERENCES DEPARTMENT(DNumber)
);
CREATE TABLE IF NOT EXISTS WORKS_ON(
    Essn INT NOT NULL,
    Pno INT NOT NULL,
    Hours INT NOT NULL,
    PRIMARY KEY (Essn, Pno),
    FOREIGN KEY (Essn) REFERENCES EMPLOYEEE(SSN),
    FOREIGN KEY (Pno) REFERENCES PROJECT(PNumber)
);
CREATE TABLE IF NOT EXISTS DEPT_LOCATIONS(
    DNumber INT NOT NULL,
    DLocation VARCHAR(50) NOT NULL,
    PRIMARY KEY (DNumber, DLocation),
    FOREIGN KEY (DNumber) REFERENCES DEPARTMENT(DNumber)
);
CREATE TABLE IF NOT EXISTS DEPENDENT(
    Essn INT NOT NULL,
    Dependent_name VARCHAR(50) NOT NULL,
    SEX ENUM("M", "F") NOT NULL,
    BDate DATE NOT NULL,
    Relationship VARCHAR(50) NOT NULL
);