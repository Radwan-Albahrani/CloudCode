// ======================= Structs =======================
// Grades struct
struct Grades
{
    string CourseName;
    double percentage;
    int credit = 0;
};


// Student Struct
struct Student
{
    string Name;
    Grades courses[100];
    int courseSize = 0;
    int ArraySize = 0;
    double GPA;
};


// ======================= Global Variables =======================
bool isModified = false;

// ======================= Functions =======================
// Function to generate timestamp
string timeStamp();
//Function to create logs:
void createLog(string log);
// Function to get data from file
void ReadStudentsFromFile(Student students[]);
// Menu
void mainMenu();
// Add students function
void addStudent(Student students[]);
// Add course to students function
void addCourse(Student students[], int i, int index);
// Remove students function
void removeStudent(Student students[], int index = -2);
// Select students
void selectStudent(Student students[]);
// Function to calculate GPA
void CalculateGPA(Student& student);
// Display all saved students
void displayAllStudents(Student students[]);
// Find students in the database
int searchStudents(const Student students[]);
// Function to search courses
int searchCourse(const Grades grades[], int size);
// Sorting Function
bool compareByCharacter(const Student &a, const Student &b);
// Function to write new data after program ends
void WriteStudentsToFile(Student students[], bool modified);
// Function to generate a report when the user asks
void GenerateReport(const Student students[]);
// Get Int from user
int getInt(string Prompt);
// Get double from user
double getDouble(string Prompt);