CREATE TABLE IF NOT EXISTS PUBLISHER(
    Name VARCHAR(50) NOT NULL PRIMARY KEY,
    Address VARCHAR(50) NOT NULL,
    Phone_number VARCHAR(50) NOT NULL
);
CREATE TABLE IF NOT EXISTS LIBRARY_BRANCH(
    Branch_id INT NOT NULL PRIMARY KEY,
    Branch_name VARCHAR(50) NOT NULL,
    address VARCHAR(50) NOT NULL
);
CREATE TABLE IF NOT EXISTS BOOK (
    Book_ID INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    Title VARCHAR(50) NOT NULL,
    Publisher_name VARCHAR(50) NOT NULL,
    FOREIGN KEY (Publisher_name) REFERENCES PUBLISHER(Name)
);
CREATE TABLE IF NOT EXISTS BOOK_AUTHORS(
    Book_ID INT NOT NULL,
    Author_ID INT NOT NULL,
    PRIMARY KEY (Book_ID, Author_ID),
    FOREIGN KEY (Book_ID) REFERENCES BOOK(Book_ID)
);
CREATE TABLE IF NOT EXISTS BOOK_COPIES(
    Book_id INT NOT NULL,
    Branch_id INT NOT NULL,
    No_of_copies INT NOT NULL,
    PRIMARY KEY (Book_id, Branch_id),
    FOREIGN KEY (Book_id) REFERENCES BOOK(Book_id),
    FOREIGN KEY (Branch_id) REFERENCES LIBRARY_BRANCH(Branch_id)
);
CREATE TABLE IF NOT EXISTS BORROWER(
    Card_no INT NOT NULL PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Address VARCHAR(50) NOT NULL,
    Phone VARCHAR(50) NOT NULL -- FOREIGN KEY (Card_no) REFERENCES BOOK_LOANS(Card_no)
);
CREATE TABLE IF NOT EXISTS BOOK_LOANS(
    Book_id INT NOT NULL,
    Branch_id INT NOT NULL,
    Card_no INT NOT NULL,
    Date_out DATE NOT NULL,
    Due_date DATE NOT NULL,
    PRIMARY KEY (Book_id, Branch_id, Card_no),
    FOREIGN KEY (Book_id) REFERENCES BOOK(Book_id),
    FOREIGN KEY (Branch_id) REFERENCES LIBRARY_BRANCH(Branch_id),
    FOREIGN KEY (Card_no) REFERENCES BORROWER(Card_no)
);