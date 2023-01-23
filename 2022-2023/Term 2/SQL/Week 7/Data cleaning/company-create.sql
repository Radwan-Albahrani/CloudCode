CREATE TABLE employee (
  fname varchar(15) not null,
  minit varchar(1),
  lname varchar(15) not null,
  ssn char(9),
  bdate date,
  address varchar(50),
  sex char,
  salary INT,
  superssn varchar(9),
  dno INT,
  primary key (ssn),
  foreign key (superssn) references employee(ssn) --  foreign key (dno) references department(dnumber)
);
CREATE TABLE department (
  dname varchar(25) not null,
  dnumber INT,
  mgrssn char(9) not null,
  mgrstartdate date,
  primary key (dnumber),
  unique (dname),
  foreign key (mgrssn) references employee(ssn)
);
ALTER TABLE employee
ADD (
    foreign key (dno) references department(dnumber)
  );
CREATE TABLE dept_locations (
  dnumber INT,
  dlocation varchar(15),
  primary key (dnumber, dlocation),
  foreign key (dnumber) references department(dnumber)
);
CREATE TABLE project (
  pname varchar(25) not null,
  pnumber INT,
  plocation varchar(15),
  dnum INT not null,
  primary key (pnumber),
  unique (pname),
  foreign key (dnum) references department(dnumber)
);
CREATE TABLE works_on (
  essn char(9),
  pno INT,
  hours INT,
  primary key (essn, pno),
  foreign key (essn) references employee(ssn),
  foreign key (pno) references project(pnumber)
);
CREATE TABLE dependent (
  essn char(9),
  dependent_name varchar(15),
  sex char,
  bdate date,
  relationship varchar(8),
  primary key (essn, dependent_name),
  foreign key (essn) references employee(ssn)
);