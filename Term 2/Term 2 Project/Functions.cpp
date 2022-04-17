#include <iostream>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>

using namespace std;

#include "Prototypes.h"

// Global Variable
bool isModified = false;


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

// Function to calculate GPA by reference
void CalculateGPA(Student& student)
{
    // Prepare total points and total credit hours
    double totalpoints = 0;
    int totalhours = 0;
    int size = student.courseSize;
    // Check if students has courses, and if not, break and return
    if(size == 0)
    {
        cout << "Student: " << student.Name << " has no courses added." << endl;
        return;
    }

    // Loop through students courses
    for(int i = 0; i < size; i++)
    {
        // Get percentage from current students
        double percentage = student.courses[i].percentage;

        // Get Credit hours from current students
        int credit = student.courses[i].credit;

        // Add hours directly to total hours
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

    // Round the GPA to 3 decimal places
    double GPA = totalpoints/totalhours;
    stringstream tmp;
    tmp << setprecision(3) << fixed << GPA;
    GPA = stod(tmp.str());
    tmp.str(string());

    // Add GPA to students
    student.GPA = GPA;

    // Making a log string
    string log;
    ostringstream buffer;
    buffer << "GPA for " << student.Name << " Has been added. Value: " << student.GPA;
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
    logfile.open("Data Files/Log.txt", ios_base::app);
    logfile << "[" << timeString << "] " << "- " << log << endl;
    logfile.close(); 
}

// Function to read students data from file
void ReadStudentsFromFile(Student students[])
{
    // A number of lines counter
    int numberOfLines = 0;

    // Variables to store line and file
    string line;
    string avoid;
    ifstream file;

    // Opening Data file
    file.open("Data Files/Data.txt");
    if(!file.is_open())
    {
        ofstream file("Data Files/Data.txt");
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

    // Start a students counter
    int studentCounter = students[0].ArraySize;

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
                        // Add A course to the student
                        students[studentCounter].courseSize++;
                        size = students[studentCounter].courseSize - 1;
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
                        students[studentCounter].courses[size].credit = stoi(substr);

                        // Reset courses counter
                        counter = 1;
                    }

                }
                
            }

            // Logging that data has been read
            string log;
            stringstream buffer;
            buffer << "Read Data for students. This includes: \n" 
            << "\tName: " << students[studentCounter].Name 
            << "\n\tCourses added: " << students[studentCounter].courseSize;
            log = buffer.str();
            createLog(log);

            // Calculate GPA of current students
            CalculateGPA(students[studentCounter]);

            // Add one to the students counter.
            studentCounter++;
            
            
        }
        else
        {
            // Creating new students
            students[0].ArraySize++;

            // add name to that students
            getline(file, line);
            students[studentCounter].Name = line;
        }
    }
}

// Function to Write new data after program ends
void WriteStudentsToFile(Student students[], bool modified)
{

    // If the database has not been modified, do not write a new one
    if(!modified)
    {
        return;
    }
    // Start file in output stream and get data
    ofstream file;
    file.open("Data Files/Data.txt");

    string timeString = timeStamp();

    // Add time to start of database
    file << "[" << timeString << "]" << endl;


    // Loop through students
    for(int i = 0; i < students[0].ArraySize; i++)
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
                // Start a new loop for the number of course of the current students
                for(int k = 0; k < students[i].courseSize; k++)
                {
                    // comma to be added at the end of each credit except the last one
                    if(k > 0 && k != students[i].courseSize)
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
                // New line after the loop for the next students
                file << endl;
            }
        }

        

    }
}

// Function to Generate a report when the user asks
void GenerateReport(const Student students[])
{
    // Open a new input file
    ifstream file;
    file.open("Data Files/Data.txt");

    // Get the date modified from data
    string dateModified;
    getline(file, dateModified);

    // Close file
    file.close();

    // Open logs
    file.open("Data Files/Log.txt");

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
        if(line.find("Read") != string::npos)
        {
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
            continue;
        }
        else if(line[0] == '\t')
        {
            getline(file, line);
            numberOfLines--;
            continue;
        }
        // If deleted is detected, add deletions
        else if(line.find("Deleted") != string::npos)
        {
            deletions++;
            continue;
        }

        // Else if modified was detected, add another modification
        else if(line.find("Modified") != string::npos)
        {
            modifications++;
            continue;
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
    report.open("Data Files/Statistical Report.txt");

    // Timestamp String
    string reportTime = "[" + timeStamp() + "]";

    // Add information to the report in Tabular Format
    report << setw(40) << left << "Report Generated at:"  << setw(5) << reportTime << endl;
    report << "===================================================================" << endl;
    report << setw(40) << left << "Number of records: " << setw(5) << students[0].ArraySize << endl;
    report << setw(40) << left << "Date since last Update: " << setw(5) << dateModified << endl;
    report << setw(40) << left << "Number of additions in total: " << setw(5) << additions << endl;
    report << setw(40) << left << "Number of deletions in total: " << setw(5) << deletions << endl;
    report << setw(40) << left << "Number of Modifications in total: " << setw(5) << modifications << endl;

}

// Main menu
void mainMenu()
{
    cout << "1 - Add Student." << endl;
    cout << "2 - Remove Student." << endl;
    cout << "3 - Select Student." << endl;
    cout << "4 - Display All Students." << endl;
    cout << "5 - Generate Report." << endl;
    cout << "6 - Exit." << endl;
}

// Function to add students
void addStudent(Student students[])
{
    if(students[0].ArraySize == 100)
    {
        cout << "Database Limit has been reached. Cannot add any more students\n";
        return;
    }
    // Get students name
    string name;
    cout << "Please enter students name: ";
    getline(cin, name);

    // Double check to ensure name isn't empty
    while(name == "" || isspace(name[0]) != 0)
    {
        cout << "Name Cannot be Empty.\n";
        cout << "Please enter students name: ";
        getline(cin, name);
    }

    // Add name to database
    students[0].ArraySize++;
    int size = students[0].ArraySize;
    students[size - 1].Name = name;

    // Start student with no courses and no GPA
    students[size - 1].courseSize = 0;
    students[size - 1].GPA = 0;
    
    // Make modified true
    isModified = true;

    // Ask if user wants to add courses
    string choice;
    while(true)
    {
        cout << "Do you want to add courses to this students right now? (Y/N): ";
        getline(cin, choice);

        // If they do
        if(tolower(choice[0]) == 'y')
        {

            // Get an integer from the user
            int counter = getInt("How many Courses do you want to add: ");

            // Loop through to add courses to a students
            for (size_t i = 0; i < counter; i++)
            {

                // Add Course
                addCourse(students, i, size - 1);
            }
            
            cout << "Courses Added Successfully.\n\n";
            CalculateGPA(students[size - 1]);
            break;
        }
        
        // if user doesn't wanna add a students
        else if(tolower(choice[0]) == 'n')
        {
            cout << "Student added to database.\n";
            break;
        }
        
        // Choice Validation
        else
        {
            cout << "Choice not Valid." << endl;
        }
    }
    
    // Logging Added students
    string addTime = timeStamp();
    stringstream buffer;
    buffer << "New Student Added.\n";
    buffer << "\tStudent Name: " << students[size - 1].Name << endl;
    buffer << "\tCourses added: " << students[size - 1].courseSize;

    string log = buffer.str();
    createLog(log);
}

// Add Course to students
void addCourse(Student students[], int i, int index)
{
    // Dont allow more than 100 courses
    if(students[index].courseSize == 100)
    {
        cout << "Limit for this student has been reached. Cannot add any more courses\n";
        return;
    }
    // Create new course
    students[index].courseSize++;
    int size = students[index].courseSize;

    // Get course index
    int courseIndex = size - 1;

    // Get Course Name
    string CourseName;

    // Prepare prompt
    string prompt;
    stringstream buffer;

    // Get the course name
    cout << "Enter Course Number " << i + 1 << "'s Name: ";
    getline(cin, CourseName);
    while(CourseName == "" || isspace(CourseName[0]) != 0)
    {
        cout << "Name Cannot be Empty.\n";
        cout << "Enter Course Number " << i + 1 << "'s Name: ";
        getline(cin, CourseName);
    }

    

    // Prepare prompt for percentage
    buffer << "Enter course number " << i + 1 << "'s Percentage Grade: ";
    prompt = buffer.str();
    buffer.str(string());

    // Ask for Percentage
    double percentage = -1;
    percentage = getDouble(prompt);

    // Make sure percentage is within Appropriate Range
    while(percentage < 0 || percentage > 100)
    {
        cout << "Input must be between 0 and 100" << endl;
        percentage = getDouble(prompt);
    }
   
    // Get credits
    buffer.str(string());
    buffer << "Enter course number " << i + 1 << "'s Credit Hours: ";
    prompt = buffer.str();
    int credit = getInt(prompt);

    // Double Check Credits
    while(credit < 0 || credit > 10)
    {
        cout << "Input must be between 0 and 10" << endl;
        credit = getDouble(prompt);
    }

    

    // Add name
    students[index].courses[courseIndex].CourseName = CourseName;
    // Add Percentage
    students[index].courses[courseIndex].percentage = percentage;
    // Add credit
    students[index].courses[courseIndex].credit = credit;
}

// Function to select Student
void selectStudent(Student students[])
{
    // Get the students
    int index = searchStudents(students);

    // If students has been received
    if(index != -1)
    {   
        // Notify Student that course was found
        cout << "Student selected Successfully. Please select an item from the menu below:\n";

        // Stick the user in this function
        while(true)
        {
            // Present Menu
            cout << "1 - Add Courses to Student.\n";
            cout << "2 - Remove Course from Student.\n";
            cout << "3 - Edit a course for Student.\n";
            cout << "4 - Delete Student.\n";
            cout << "5 - Back to main Menu.";
            
            // Get the user's Choice
            int choice = getInt("\n\nPlease Select an Item from the menu: ");

            // If 1, add a course to the students
            if(choice == 1)
            {
                // Get Old Course size
                int CourseSize = students[index].courseSize;

                // Get How many courses the user wants to add
                int counter = getInt("How many courses do you want to add: ");

                // Loop through and add courses
                for(int i = 0; i < counter; i++)
                {

                    // Add Course
                    addCourse(students, i, index);
                }
                // Tell user
                cout << "Courses added Successfully.\n\n";

                // Calculate GPA
                CalculateGPA(students[index]);
                
                // Mark the file as modified
                isModified = true;

                // Mark Record as modified
                stringstream buffer;
                string log;
                buffer << "Modified Courses for Student: " << students[index].Name;
                buffer << " - Old Course Total:  " << CourseSize;
                buffer << " - New Course Total: " << students[index].courseSize;
                log = buffer.str();
                createLog(log);

            }

            // Remove a course
            else if(choice == 2)
            {
                // Get course index
                int courseIndex = searchCourse(students[index].courses, students[index].courseSize);
                if(courseIndex != -1)
                {
                    int size = students[index].courseSize;
                    // Get course name and save it
                    string courseName = students[index].courses[courseIndex].CourseName;

                    // Get course and delete it
                    for (int j = courseIndex; j < size; j++)
                    {
                        students[index].courses[j] = students[index].courses[j+1];
                    }
                    students[index].courseSize = size - 1;
                    cout << "Course Deleted Successfully.\n";

                    // Mark File as modified
                    isModified = true;

                    // Log it
                    stringstream buffer;
                    string log;
                    buffer << "Course deleted Successfully. Course name: " << courseName << ". Student Data has been Modified.";  
                    
                    log = buffer.str();
                    createLog(log);

                    // Recalculate GPA
                    CalculateGPA(students[index]);
                }
            }

            // Modify Course
            else if(choice == 3)
            {
                // Get course
                int courseIndex = searchCourse(students[index].courses, students[index].courseSize);
                
                if(courseIndex != -1)
                {
                    // Make Sure Course is modified
                    bool courseModified = false;
                    
                    // Save old course information
                    Grades oldCourse = students[index].courses[courseIndex];

                    cout << "Course selected Successfully. Please select an item from the menu below:\n";
                    while(true)
                    {                     
                        // Present new menu
                        
                        cout << "1 - Change Course Name.\n";
                        cout << "2 - Change Course Grade.\n";
                        cout << "3 - Change Course Credit.\n";
                        cout << "4 - Return to Previous Menu\n\n";

                        int choice = getInt("Please Select Item From Menu: ");
                        // Change course name
                        if(choice == 1)
                        {
                            // Get New Course name
                            string name;
                            cout << "Enter New Course Name: ";
                            getline(cin, name);

                            // Update course name
                            students[index].courses[courseIndex].CourseName = name;
                            isModified = true;
                            courseModified = true;
                            cout << "Course Name Updated.\n";
                        }
                        // Change Course Percentage
                        else if(choice == 2)
                        {
                            // Get New Percentage
                            double percentage = getDouble("Please Enter New Percentage: ");
                            while(percentage < 0 || percentage > 100)
                            {
                                cout << "Input must be between 0 and 100" << endl;
                                percentage = getDouble("Please Enter New Percentage: ");
                            }
                            // Update and notify
                            students[index].courses[courseIndex].percentage = percentage;
                            isModified = true;
                            courseModified = true;
                            cout << "Course Percentage Updated.\n";
                        }
                        // Change course Credit
                        else if(choice == 3)
                        {
                            int credit = getInt("Please Enter New Credit Hours: ");
                            while(credit < 0 || credit > 10)
                            {
                                cout << "Input must be between 0 and 10" << endl;
                                credit = getInt("Please Enter New Credit Hours: ");
                            }
                            // Update and Notify
                            students[index].courses[courseIndex].credit = credit;
                            isModified = true;
                            courseModified = true;
                            cout << "Course Credit Updated.\n";
                        }
                        // Return To Previous Menu
                        else if(choice == 4)
                        {
                            cout << "Returning to Previous Menu. \n\n";
                            break;
                        }

                        // Notify user choice was not found
                        else
                        {
                            cout << "Choice not found. Make sure the number is within The Menu\n";
                        }
                    }

                    // If the course was modified, Log it and Update it
                    if(courseModified)
                    {
                        stringstream buffer;
                        string log;
                        buffer << "Courses Modified. Course with (old) name - " << oldCourse.CourseName << " - Has been changed.";
                        log = buffer.str();
                        createLog(log);
                    }
                }
            }

            // If user wants to delete students
            else if(choice == 4)
            {
                removeStudent(students, index);
                break;
            }

            // Else if user wants to return to main menu
            else if(choice == 5)
            {
                break;
            }

            // Notify User choice was not found
            else
            {
                cout << "Choice not found. Make sure the number is within The Menu\n";
            }
        }
    }
}

// Function to remove Students
void removeStudent(Student students[], int index)
{
    if(index == -2)
    {
        index = searchStudents(students);
    }
    

    if(index != -1)
    {
        // Log it before deleting it
        stringstream buffer;
        string log;
        buffer << "Student with name " << students[index].Name << " Has been Deleted.";
        log = buffer.str();
        createLog(log);

        // Delete students in that index spot
        int size = students[0].ArraySize - 1;
        for (int j = index; j < size; j++)
        {
            students[j] = students[j+1];
        }
        students[0].ArraySize = size;
        // Inform user
        cout << "Student has been deleted successfully" << endl;
        
        // Tag file to be modified
        isModified = true;
    }
}

// Search for and select one students from the database
int searchStudents(const Student students[])
{
    int size = students[0].ArraySize;
    if(size == 0)
    {
        cout << "No students in Database." << endl;
        return -1;
    }

    // Ask for students name
    string name;
    cout << "Please enter Student name: ";
    getline(cin, name);

    // Loop through array of students and find all cases of students with that name
    vector<int> index;
    for (size_t i = 0; i < size; i++)
    {
        // Get the name of the current student 
        string currentName = students[i].Name;

        // Lowercase the whole name
        for (size_t j = 0; j < currentName.length(); j++)
        {
            currentName[j] = tolower(currentName[j]);
        }

        // Lower case the name of the search query
        for (size_t j = 0; j < name.length(); j++)
        {
            name[j] = tolower(name[j]);
        }
        
        // Find any occurrence of the search query in the current student name
        size_t found = currentName.find(name);

        // If found, add its index over to the index vector
        if(found != string::npos)
        {
            index.push_back(i);
        }
    }

    // If more than one case
    if(index.size() > 0)
    {   
        // Display all found students
        cout << "Student Found. Please Select Student from the list: " << endl;
        cout << setw(5) << left << "ID";
        cout << setw(20) << "Name";
        cout << setw(10) << "Courses";
        cout << endl;

        // Loop through index and display all found students
        for(int i = 0; i < index.size(); i++)
        {
            cout << setw(5) << left << i;
            cout << setw(20) << students[index[i]].Name;
            
            // If student has no courses, Tell user then go to new line
            if(students[index[i]].courseSize == 0)
            {
                cout << setw(10) << "No Courses Found." << endl;
            }
            
            // Loop through courses and display them one by one in tabular format
            for(int j = 0; j < students[index[i]].courseSize; j++)
            {
                if(j == 0)
                {
                    cout << setw(10) << students[index[i]].courses[j].CourseName << endl;
                }
                else
                {
                    cout << setw(5) << left << "" << setw(20) << "" << setw(10) << students[index[i]].courses[j].CourseName << endl;
                }
            }

            // Seperator
            cout << "=============================================================" << endl;
        }
        // Ask user for ID and validate it
        int id = getInt("\nPlease Select by ID: ");
        while(id > index.size() - 1 || id < 0)
        {
            cout << "ID is not on the list. Please check again\n";
            id = getInt("\nPlease Select by ID: ");
        } 
        return index[id];
    }

    // If no students were found, inform user
    else
    {
        cout << "No students found with this name. Please make sure the name is spelled correctly." << endl;
        return -1;
    }

    return -1;

}

// Search course
int searchCourse(const Grades courses[], int size)
{
    // Make sure courses exists
    if(size == 0)
    {
        cout << "Student has no courses" << endl;
        return -1;
    }

    // Ask for course name
    string name;
    cout << "Please enter course name: ";
    getline(cin, name);

    // Find any courses with that name
    vector<int> index;
    for (size_t i = 0; i < size; i++)
    {
        // Get the name of the current student 
        string currentName = courses[i].CourseName;

        // Lowercase the whole name
        for (size_t j = 0; j < currentName.length(); j++)
        {
            currentName[j] = tolower(currentName[j]);
        }

        // Lower case the name of the search query
        for (size_t j = 0; j < name.length(); j++)
        {
            name[j] = tolower(name[j]);
        }
        
        // Find any occurrence of the search query in the current course name
        size_t found = currentName.find(name);

        // If found, add its index over to the index vector
        if(found != string::npos)
        {
            index.push_back(i);
        }
    }

    // If more than one course
    if(index.size() > 0)
    {   
        // Display all found courses
        cout << "Course Found. Please Select Student from the list: " << endl;
        cout << setw(5) << left << "ID";
        cout << setw(10) << "Courses";
        cout << endl;

        // Loop through index and display all found courses
        for(int i = 0; i < index.size(); i++)
        {
            cout << setw(5) << left << i;
            cout << setw(10) << courses[index[i]].CourseName;
            cout << endl;
        }
        // Ask user for ID and validate it
        int id = getInt("Please Select by ID: ");

        // Validate ID
        while(id > index.size() - 1 || id < 0)
        {
            cout << "ID is not on the list. Please check again\n";
            id = getInt("\nPlease Select by ID: ");
        } 
        return index[id];
        return index[id];
    }

    // If no students were found, inform user
    else
    {
        cout << "No Courses found with this name. Please make sure the Course name is spelled correctly." << endl;
        return -1;
    }

    return -1;


}

// Function to Display All students Neatly
void displayAllStudents(Student students[])
{   
    // Saving Student size
    int size = students[0].ArraySize;

    // If no students, Tell user
    if(size == 0)
    {
        cout << "No Students in Database\n";
        return;
    }
    // Display all students in Tabular Format
    cout << "Displaying Students: " << endl;
    cout << setw(20) << left << "Name";
    cout << setw(30) << "Courses";
    cout << setw(10) << "Percent";
    cout << setw(5) << "Credit"; 
    cout << endl;

        // Loop through all students and Display appropriate information in appropriate Columns
        for(int i = 0; i < size; i++)
        {
            cout << setw(20) << students[i].Name;
            if(students[i].courseSize == 0)
            {
                cout << setw(30) << "Student Has No courses Added";
            }
            for(int j = 0; j < students[i].courseSize; j++)
            {
                if(j == 0)
                {
                    cout << setw(30) << students[i].courses[j].CourseName 
                    << setw(10) << students[i].courses[j].percentage 
                    << setw(5) << students[i].courses[j].credit << endl;
                }
                else
                {
                    cout << setw(20)  << left << "" 
                    << setw(30) << students[i].courses[j].CourseName 
                    << setw(10) << students[i].courses[j].percentage 
                    << setw(5) << students[i].courses[j].credit << endl;
                }
            }
           cout << endl 
           << setw(20) << left << "" 
           << setw(10) << "GPA: " << students[i].GPA 
           << endl << "=================================================================" << endl;
        }
}

// Get Int from user
int getInt(string Prompt)
{
    // Initiate Variables
    string choice;
    int realChoice = 0;

    // Start a loop
    while(true)
    {
         // Try except to see if can get a number
        try
        {
            cout << Prompt; 
            getline(cin, choice);
            realChoice = stoi(choice);
            break;
            
        }

        // Yell user it must be a number
        catch(const std::exception& e)
        {
            cout << "Input must be a number. Try again.\n";
            continue;
        }
    }
   return realChoice;
}

// Get Double
double getDouble(string Prompt)
{
    // Initiate Variables
    string choice;
    double realChoice = 0;

    // Start a loop
    while(true)
    {
         // Try except to see if can get a number
        try
        {
            cout << Prompt; 
            getline(cin, choice);
            realChoice = stod(choice);
            break;
            
        }

        // Yell user it must be a number
        catch(const std::exception& e)
        {
            cout << "Input must be a number. Try again.\n";
            continue;
        }
    }
   return realChoice;
}

// Sorting Function
bool compareByCharacter(const Student &a, const Student &b)
{
    return tolower(a.Name[0]) < tolower(b.Name[0]);
}