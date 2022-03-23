/*

TODO:
    -We need a menu. #Ammar
    -A Search a student #Abdulmalik
    -We need a function to add a student. #Abdulelah
    -A function to remove a student. #ammar and salman
    -A function to edit student courses.  #Abdulelah and Abdulmalik
    -A function to add a course to a student. #Radwan
    -A function to remove a course from a student. #Radwan
    -A function to display student information. #Salman

*/

// Including
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

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
    vector<Grades> courses;
    double GPA;
};

// Function to calculate GPA
void CalculateGPA(Student&, int);

//Function to create logs:
void createLog(string log);

// Function to get data from file
void ReadStudentsFromFile(vector<Student>& students, vector<int>& coursePerStudent);

// Main function
int main(int argc, char const *argv[])
{
    vector<int> coursePerStudent;
    
    // Create a students vector.
    vector<Student> students;
    
    ReadStudentsFromFile(students, coursePerStudent);
    
    // Print GPA
    cout << students[0].GPA << endl;
    cout << students[1].GPA << endl;
    cout << students.size();
    
    return 0;
}

// Function to calculate GPA by reference
void CalculateGPA(Student& students, int size)
{
    // Prepare total points and total credit hours
    double totalpoints = 0;
    int totalhours = 0;

    // Check if students has courses, and if not, break and return
    if(students.courses[0].credit == 0)
    {
        cout << "Given students has no courses added.";
        return;
    }

    // Loop through students courses
    for(int i = 0; i < size; i++)
    {
        // Get percentage from current students
        double percentage = students.courses[i].percentage;

        // Get Credit hours from current students
        int credit = students.courses[i].credit;

        // Add hours directly to total houts
        totalhours += credit;

        // Convert percentage to raw score based on IAU metrics.
        if(percentage >= 95 && percentage <= 100)
        {
            totalpoints += credit * 5.00;
        }
        else if(percentage >= 90 && percentage < 95)
        {
            totalpoints += credit * 4.75;
        }
        else if(percentage >= 85 && percentage < 90)
        {
            totalpoints += credit * 4.50;
        }
        else if(percentage >= 80 && percentage < 85)
        {
            totalpoints += credit * 4.00;
        }
        else if(percentage >= 75 && percentage < 80)
        {
            totalpoints += credit * 3.50;
        }
        else if(percentage >= 70 && percentage < 75)
        {
            totalpoints += credit * 3.00;
        }
        else if(percentage >= 60 && percentage < 70)
        {
            totalpoints += credit * 2.50;
        }
        else
        {
            totalpoints += credit * 2.00;
        }

    }

    // Put students GPA into profile
    students.GPA = totalpoints/totalhours;

    // Making a log string
    string log;
    ostringstream buffer;
    buffer << "GPA for " << students.Name << " Has been added. Value: " << students.GPA;
    log = buffer.str();

    // Creating log through function.
    createLog(log);

}

// Function to create a log
void createLog(string log)
{
    // Get current time
    time_t curr_time = time(0);
	tm * curr_tm;
	char timeString[100];
	
    // Get local time from the time variable
	curr_tm = localtime(&curr_time);
    
    // Convert time to string
	strftime(timeString, 50, "%m/%d/%Y | %I:%M:%S%p", curr_tm);
    
    // Adding Log
    ofstream logfile;
    logfile.open("Log.txt", ios_base::app);
    logfile << "[" << timeString << "] " << "- " << log << endl;
    logfile.close(); 
}

// Function to read student data from file
void ReadStudentsFromFile(vector<Student>& students, vector<int>& coursePerStudent)
{
    // A number of lines counter
    int numberOfLines = 0;

    // Variables to store line and file
    string line;
    ifstream file;

    // Opening Data file
    file.open("Data.txt");

    // Get the number of lines
    while(getline(file, line))
    {
        numberOfLines++;
    }
    
    // Get back to beginning of file
    file.clear();
    file.seekg(0);
    
    // Start the courses counter
    int counter = 1;

    // Start a student counter
    int studentCounter = students.size();

    // Loop through the lines
    for(int i = 1; i <= numberOfLines; i++)
    {
        // If the line is even, we need to get all the courses registered
        if(i % 2 == 0)
        {
            // Get the entire line
            getline(file, line);

            // Put the line in a stream
            stringstream sstr(line);
            
            // While there is still stuff in the stream
            while(sstr.good())
            {
                // Create a substring up until the first comma
                string substr;
                getline(sstr, substr, ',');

                // Creating courses object for that student
                students[studentCounter].courses.push_back(Grades());

                // If the courses counter is 1, we are at the course name. Get it and add it to the proper place
                if(counter == 1)
                {
                    students[studentCounter].courses[coursePerStudent[studentCounter]].CourseName = substr;
                    counter++;
                }

                // If the course counter is 2, we are at the percentage. Get it and add it to the proper place
                else if(counter == 2)
                {
                    students[studentCounter].courses[coursePerStudent[studentCounter]].percentage = stod(substr);
                    counter++;
                }
                // If the courses counter is 3, We are at credit score
                else
                {
                    // add credit score to proper place
                    students[studentCounter].courses[coursePerStudent[studentCounter]].credit = stod(substr);

                    // Reset courses counter
                    counter = 1;

                    // Add 1 to the number of courses to that student.
                    coursePerStudent[studentCounter]++;
                }

            }
            
            // Logging that data has been read
            string log;
            stringstream buffer;
            buffer << "Read Data for student. This includes: \n" << "\tName: " << students[studentCounter].Name << "\n\tCourses added: " << coursePerStudent[studentCounter];
            log = buffer.str();
            createLog(log);

            // Calculate GPA of current student
            CalculateGPA(students[studentCounter], coursePerStudent[studentCounter]);

            // Add one to the student counter.
            studentCounter++;
            
        }
        else
        {
            // Creating new student
            students.push_back(Student());
            
            // Creating courses per student for that student
            coursePerStudent.push_back(0);

            // add name to that student
            getline(file, line);
            students[studentCounter].Name = line;
        }
    }
}