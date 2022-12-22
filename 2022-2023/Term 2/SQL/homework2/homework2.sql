-- Task 1
CREATE TABLE IF NOT EXISTS teachers (
    tch_id int AUTO_INCREMENT,
    tch_name VARCHAR(50) NOT NULL,
    tch_birth Date,
    course_name VARCHAR(50) NOT NULL,
    PRIMARY KEY (tch_id)
) AUTO_INCREMENT = 1000;
CREATE TABLE IF NOT EXISTS students (
    std_id int AUTO_INCREMENT,
    std_name VARCHAR(50) NOT NULL,
    std_birth Date,
    std_group ENUM("G1", "G2", "G3", "G4") NOT NULL,
    tch_id int NOT NULL,
    PRIMARY KEY (std_id),
    FOREIGN KEY (tch_id) REFERENCES teachers(tch_id)
) AUTO_INCREMENT = 2000;
-- Task 2
ALTER TABLE students DROP COLUMN std_birth;
ALTER TABLE students
ADD COLUMN std_birth Date
AFTER std_name;
-- Task 3
INSERT INTO teachers (tch_name, tch_birth, course_name)
VALUES (
        'Dr. Ahmed Abdullah',
        '1977-5-20',
        'Database Concepts and Design'
    ),
    (
        "Dr. Ali Ahmed",
        "1975-4-21",
        "Network"
    ),
    (
        "Dr.Abdullah Khalid",
        "1978-3-20",
        "System Analysis"
    ),
    (
        "Dr.Ibrahim Mohammed",
        "1978-2-20",
        "Database Management System"
    );
INSERT INTO students (std_name, std_birth, std_group, tch_id)
VALUES (
        'Abdullah',
        '1999-2-20',
        'G1',
        1000
    ),
    (
        'Ahmed',
        '1998-3-13',
        'G2',
        1002
    ),
    (
        'Fahad',
        '1999-4-27',
        'G3',
        1003
    ),
    (
        'Nasser',
        '1998-2-15',
        'G4',
        1001
    ),
    (
        'Ibrahim',
        '1999-5-18',
        'G3',
        1002
    ),
    (
        'Saleh',
        '1998-2-20',
        'G4',
        1003
    );
ALTER TABLE students
ADD COLUMN address VARCHAR(50)
AFTER std_group;
UPDATE students
SET std_group = 'G4'
WHERE std_id = 2001;
UPDATE students
SET std_name = "Nasser",
    tch_id = 1002
WHERE std_id = 2002;