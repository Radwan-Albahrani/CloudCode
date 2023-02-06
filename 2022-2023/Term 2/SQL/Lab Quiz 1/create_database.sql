DROP DATABASE IF EXISTS Garden;
CREATE DATABASE Garden;
Use Garden;

CREATE TABLE Owner (
    OwnerID INT NOT NULL AUTO_INCREMENT,
    OwnerName VARCHAR(20) NOT NULL,
    OwnerEmailAddress VARCHAR(20) NOT NULL,
    OwnerType VARCHAR(20) NOT NULL,
    PRIMARY KEY (OwnerID)
);

CREATE TABLE OWNED_PROPERTY (
    PropertyID INT NOT NULL AUTO_INCREMENT,
    OwnerID INT NOT NULL,
    PropertyType VARCHAR(20) NOT NULL,
    Street VARCHAR(20) NOT NULL,
    City VARCHAR(20) NOT NULL,
    zip VARCHAR(20) NOT NULL,
    PRIMARY KEY (PropertyID, OwnerID)
);
CREATE TABLE GG_SERVICE (
    ServiceID INT NOT NULL AUTO_INCREMENT,
    ServiceDescription VARCHAR(25) NOT NULL,
    CostPerHour INT NOT NULL,
    PRIMARY KEY (ServiceID)
);

CREATE TABLE EMPLOYEE (
    EmployeeID INT NOT NULL AUTO_INCREMENT,
    LastName VARCHAR(20) NOT NULL,
    FirstName VARCHAR(20) NOT NULL,
    CellPhone VARCHAR(20) NOT NULL,
    ExperienceLevel VARCHAR(20) NOT NULL,
    PRIMARY KEY (EmployeeID)
);

CREATE TABLE PROPERTY_SERVICE(
    PropertyServiceID INT NOT NULL AUTO_INCREMENT,
    PropertyID INT NOT NULL,
    ServiceID INT NOT NULL,
    ServiceDate DATE NOT NULL,
    EmployeeID INT NOT NULL,
    HoursWorked INT NOT NULL,
    PRIMARY KEY(PropertyServiceID, PROPERTYID)
);

ALTER TABLE OWNED_PROPERTY
ADD CONSTRAINT FK_OWNED_PROPERTY_OWNERID
FOREIGN KEY (OwnerID) REFERENCES OWNER(OwnerID);

ALTER TABLE PROPERTY_SERVICE
ADD CONSTRAINT FK_PROPERTY_SERVICE_PROPERTYID
FOREIGN KEY (PropertyID) REFERENCES OWNED_PROPERTY(PropertyID);

ALTER TABLE PROPERTY_SERVICE
ADD CONSTRAINT FK_PROPERTY_SERVICE_SERVICEID
FOREIGN KEY (ServiceID) REFERENCES GG_SERVICE(ServiceID);

ALTER TABLE PROPERTY_SERVICE
ADD CONSTRAINT FK_PROPERTY_SERVICE_EMPLOYEEID
FOREIGN KEY (EmployeeID) REFERENCES EMPLOYEE(EmployeeID);

INSERT INTO Owner (OwnerName, OwnerEmailAddress, OwnerType)
VALUES('Jack Black', 'JackBlack@gmail.com', "Individual"),
('Jane Brown', 'JaneBrown@gmail.com', "Corporate"),
('John Doe', 'JohnDoe@gmail.com', "Individual"),
('Jim Green', 'JimGreen@gmail.com', "Individual"),
('Jane White', 'JaneWhite@gmail.com', "Corporate");

INSERT INTO OWNED_PROPERTY (OwnerID, PropertyType, Street, City, zip)
VALUES(1, "Residential", "1st Ave", "New York", "10001"),
(2, "Commercial", "2nd Ave", "Los Angeles", "90001"),
(3, "Residential", "3rd Ave", "Chicago", "60001"),
(1, "Commercial", "4th Ave", "Houston", "70001"),
(2, "Residential", "5th Ave", "Philadelphia", "19001");

INSERT INTO GG_SERVICE (ServiceDescription, CostPerHour)
VALUES("Lawn Mowing", 50),
("Tree Trimming", 75),
("Fertilization", 100),
("Weeding", 30),
("Irrigation", 80);

INSERT INTO EMPLOYEE (LastName, FirstName, CellPhone, ExperienceLevel)
VALUES("Smith", "John", "555-555-5555", "Master"),
("Johnson", "David", "555-555-5556", "Master"),
("Williams", "Jack", "555-555-5557", "Beginner"),
("Jones", "Robert", "555-555-5558", "Master"),
("Brown", "Michael", "555-555-5559", "Intermediate");

INSERT INTO PROPERTY_SERVICE (PropertyID, ServiceID, ServiceDate, EmployeeID, HoursWorked)
VALUES(1, 1, "2022-01-01", 1, 4),
(2, 2, "2022-02-01", 2, 5),
(3, 3, "2022-03-01", 3, 6),
(1, 4, "2022-04-01", 4, 3),
(2, 5, "2022-05-01", 5, 2);
