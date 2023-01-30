DROP TABLE employee;

CREATE TABLE employee (
   empID INT NOT NULL,
   name varchar (20) NOT NULL,
   department varchar (10) NOT NULL,
   salary INT NOT NULL,
   PRIMARY KEY (empID)
);

INSERT INTO employee (empID, name, department, salary )
VALUES 
   (1255,'Mohammad','IT',8500), 
   (1256,'Omar','IT',9000),
   (1300,'Lama','HR',6000), 
   (1310,'Sara','HR',5900);
