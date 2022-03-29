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
#include <iomanip>
using namespace std;


// ======================= Structs =======================
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


// ======================= Global Variables =======================
bool isModified = false;

// ======================= Functions =======================
// Sorting Function
bool compareByCharacter(const Student &a, const Student &b);

// Function to calculate GPA
void CalculateGPA(Student&, int);

//Function to create logs:
void createLog(string log);

// Function to get data from file
void ReadStudentsFromFile(vector<Student>& students);

// Function to write new data after program ends
void WriteStudentsToFile(vector<Student>& students, bool modified);

// Function to generate timestamp
string timeStamp();

// Function to generate a report when the user asks
void GenerateReport(const vector<Student> students);

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
    cout << students.size() << endl;

    // Generate report
    GenerateReport(students);

    // Update database if necessary
    WriteStudentsToFile(students, isModified);
    
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
    // Get timestamp
    string timeString = timeStamp();
    
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
    string avoid;
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
    
    // Skip first line
    getline(file, line);
    numberOfLines--;

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
void WriteStudentsToFile(vector<Student>& students, bool modified)
{

    // If the database has not been modified, do not write a new one
    if(!modified)
    {
        return;
    }
    // Start file in output stream and get data
    ofstream file;
    file.open("Data.txt");

    string timeString = timeStamp();

    // Add time to start of database
    file << "[" << timeString << "]" << endl;


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

// Function to generate a timestamp
string timeStamp()
{
    // Get current time
    time_t curr_time = time(0);
	tm * curr_tm;
	char timeString[100];
	
    // Get local time from the time variable
	curr_tm = localtime(&curr_time);
    
    // Convert time to string
	strftime(timeString, 50, "%m/%d/%Y | %I:%M:%S%p", curr_tm);

    return timeString;
}

// Function to Generate a report when the user asks
void GenerateReport(const vector<Student> students)
{
    // Open a new input file
    ifstream file;
    file.open("Data.txt");

    // Get the date modified from data
    string dateModified;
    getline(file, dateModified);

    // Close file
    file.close();

    // Open logs
    file.open("Log.txt");

    // string to store each line
    string line;
    // Loop through number of lines to count
    int numberOfLines = 0;
    while(getline(file, line))
    {
       numberOfLines++;
    }

    // Preparing report Variables
    int modifications = 0;
    int additions = 0;
    int deletions = 0;

    // Go back to beginning of file
    file.clear();
    file.seekg(0);

    // Start a loop through the file
    for (size_t i = 0; i < numberOfLines; i++)
    {
        // Get the line
        getline(file, line);

        // If the line includes read, Skip two lines and continue loop
        if(line.find("Read") != string::npos || line[0] == ' ')
        {
            numberOfLines -= 2;
            getline(file, line);
            getline(file, line);
            continue;
        }

        // If the line includes GPA, skip this loop (GPA is added Automatically and is not considered a modification)
        else if(line.find("GPA") != string::npos)
        {
            continue;
        }

        // if added is in log, add additions
        else if(line.find("Added") != string::npos)
        {
            additions++;
        }
        
        // If deleted is detected, add deletions
        else if(line.find("Deleted") != string::npos)
        {
            deletions++;
        }

        // Else if modified was detected, add another modification
        else if(line.find("Modified") != string::npos)
        {
            modifications++;
        }
        else
        {
            cout << "This type of log was not accounted for: " << line << endl;
        }
    }
    
    // Close the file
    file.close();

    // Create a report file
    ofstream report;
    report.open("Statistical Report.txt");

    // Timestamp String
    string reportTime = "[" + timeStamp() + "]";

    // Add information to the report in Tabular Format
    report << setw(40) << left << "Report Generated at:"  << setw(5) << reportTime << endl;
    report << "===================================================================" << endl;
    report << setw(40) << left << "Number of records: " << setw(5) << students.size() << endl;
    report << setw(40) << left << "Date since last Update: " << setw(5) << dateModified << endl;
    report << setw(40) << left << "Number of additions in total: " << setw(5) << additions << endl;
    report << setw(40) << left << "Number of deletions in total: " << setw(5) << deletions << endl;
    report << setw(40) << left << "Number of Modifications in total: " << setw(5) << modifications << endl;

}





// Sorting Function
bool compareByCharacter(const Student &a, const Student &b)
{
    return tolower(a.Name[0]) < tolower(b.Name[0]);
}