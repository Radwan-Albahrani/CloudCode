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
#include <algorithm>
using namespace std;

// Grades struct
struct Grades
{
    string CourseName;
    double percentage;
    double credit = 0;
};


// Student Struct
struct Student
{
    string Name;
    vector<Grades> courses;
    double GPA;
};

// Sorting Function
bool compareByCharacter(const Student &a, const Student &b);

// Function to calculate GPA
void CalculateGPA(Student&, int);

//Function to create logs:
void createLog(string log);

// Function to get data from file
void ReadStudentsFromFile(vector<Student>& students);

// Function to write new data after program ends
void WriteStudentsToFile(vector<Student>& students);

// Main function
int main(int argc, char const *argv[])
{
    // Create a students vector.
    vector<Student> students;
    
    ReadStudentsFromFile(students);

    // Test Adding Students Test
    // students.push_back(Student());
    // students[students.size()-1].Name = "Bader";
    // students[students.size()-1].courses.push_back(Grades());
    // students[students.size()-1].courses[0].CourseName = "Computer Science";
    // students[students.size()-1].courses[0].percentage = 70;
    // students[students.size()-1].courses[0].credit = 3.5;
    // CalculateGPA(students[students.size()-1], students[students.size()-1].courses.size());
    
    // Quickly Sort by First letter.
    sort(students.begin(), students.end(), compareByCharacter);
    
    // Print GPA
    cout << students[0].GPA << endl;
    cout << students[1].GPA << endl;
    cout << students.size();
    
    WriteStudentsToFile(students);
    
    return 0;
}

// Function to calculate GPA by reference
void CalculateGPA(Student& students, int size)
{
    // Prepare total points and total credit hours
    double totalpoints = 0;
    int totalhours = 0;

    // Check if students has courses, and if not, break and return
    if(size == 0)
    {
        cout << "Student: " << students.Name << " has no courses added." << endl;
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
void ReadStudentsFromFile(vector<Student>& students)
{
    // A number of lines counter
    int numberOfLines = 0;

    // Variables to store line and file
    string line;
    ifstream file;

    // Opening Data file
    file.open("Data.txt");
    if(!file.is_open())
    {
        ofstream file("Data.txt");
        return;
    }

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
            if (line == "")
            {
                cout << "Data contains Student with no courses." << endl;
            }
            else
            {
                // Put the line in a stream
                stringstream sstr(line);
                
                int size = 0;
                // While there is still stuff in the stream
                while(sstr.good())
                {
                    // Create a substring up until the first comma
                    string substr;
                    getline(sstr, substr, ',');

                    // If the courses counter is 1, we are at the course name. Get it and add it to the proper place
                    if(counter == 1)
                    {
                        // Creating a new Grades Object and Starting with it.
                        students[studentCounter].courses.push_back(Grades());
                        size = students[studentCounter].courses.size() - 1;
                        students[studentCounter].courses[size].CourseName = substr;
                        counter++;
                    }

                    // If the course counter is 2, we are at the percentage. Get it and add it to the proper place
                    else if(counter == 2)
                    {
                        students[studentCounter].courses[size].percentage = stod(substr);
                        counter++;
                    }
                    // If the courses counter is 3, We are at credit score
                    else
                    {
                        // add credit score to proper place
                        students[studentCounter].courses[size].credit = stod(substr);

                        // Reset courses counter
                        counter = 1;
                    }

                }
                
            }

            // Logging that data has been read
            string log;
            stringstream buffer;
            buffer << "Read Data for student. This includes: \n" << "\tName: " << students[studentCounter].Name << "\n\tCourses added: " << students[studentCounter].courses.size();
            log = buffer.str();
            createLog(log);

            // Calculate GPA of current student
            CalculateGPA(students[studentCounter], students[studentCounter].courses.size());

            // Add one to the student counter.
            studentCounter++;
            
            
        }
        else
        {
            // Creating new student
            students.push_back(Student());

            // add name to that student
            getline(file, line);
            students[studentCounter].Name = line;
        }
    }
}

// Function to Write new data after program ends
void WriteStudentsToFile(vector<Student>& students)
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
    file.close();

    // If there were no updates, stop the function
    if((numberOfLines/2) == students.size())
    {
        return;
    }

    // If updates must be made
    else
    {
        // Start file in output stream and get data
        ofstream file;
        file.open("Data.txt");
        
        // Loop through students
        for(int i = 0; i < students.size(); i++)
        {
            // Loop through elements of students
            for(int j = 0; j < 2; j++)
            {
                // if we at element 1, we are at name. Put the name in file and start a new line. Go to next loop
                if(j == 0)
                {
                    string name = students[i].Name;
                    file << name << endl;
                    continue;
                }
                
                // If we are at courses
                if(j == 1)
                {
                    // Start a new loop for the number of course of the current student
                    for(int k = 0; k < students[i].courses.size(); k++)
                    {
                        // comma to be added at the end of each credit except the last one
                        if(k > 0 && k != students[i].courses.size())
                        {
                            file << ",";
                        }
                        // Add course name then a comma
                        file << students[i].courses[k].CourseName << ",";
                        
                        // Add course percentage then add a comma
                        file << students[i].courses[k].percentage << ",";

                        // Add course credit
                        file << students[i].courses[k].credit;
                    }
                    // New line after the loop for the next student
                    file << endl;
                }
            }

        }

    }
}

// Sorting Function
bool compareByCharacter(const Student &a, const Student &b)
{
    return tolower(a.Name[0]) < tolower(b.Name[0]);
}