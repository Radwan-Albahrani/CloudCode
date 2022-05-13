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
	strftime(timeString, 50, "[%m/%d/%Y | %I:%M:%S%p]", curr_tm);

    // Return timestring
    return timeString;
}

// Function to calculate GPA by reference
void CalculateGPA(Student& student)
{
    // Prepare total points and total credit hours
    double totalpoints = 0;
    int totalhours = 0;
    int size = student.courseSize;
    
    // Check if students has courses, and if not, Tell user, then return
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

    // Calculate GPA
    double GPA = totalpoints/totalhours;

    // Start a temporary String Stream
    stringstream tmp;

    // Set precision to 3 decimal places and add in GPA
    tmp << setprecision(3) << fixed << GPA;

    // Convert string to double and put it in GPA
    GPA = stod(tmp.str());

    // Reset Temporary string stream
    tmp.str(string());

    // Add GPA to students
    student.GPA = GPA;

    // Make a log of the added GPA
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
    
    // Adding Log to the logfile
    ofstream logfile;
    logfile.open("Data Files/Log.txt", ios_base::app);
    logfile << timeString << " - " << log << endl;
    logfile.close(); 
}

// Function to read students data from file
void ReadStudentsFromFile(Student students[])
{
    // A number of lines counter
    int numberOfLines = 0;

    // Variables to store line and file
    string line;
    ifstream file;

    // Opening Data file
    file.open("Data Files/Data.txt");

    // If the data file doesn't exist yet
    if(!file.is_open())
    {
        // Create new Data file
        ofstream file("Data Files/Data.txt");
        string timeString = timeStamp();

        // Add time to start of data
        file << timeString << endl;
        file.close();

        // Exit Function
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
    
    // Skip first line (Contains timestamp)
    getline(file, line);
    numberOfLines--;

    // Try Reading Data
    try
    {
        // Start the courses counter
        int counter = 1;

        // Loop through the lines
        for(int i = 1; i <= numberOfLines; i++)
        {
            // If the line is even, we need to get all the courses registered
            if(i % 2 == 0)
            {
                // Start a students Index at the current student
                int StudentIndex = students[0].ArraySize - 1;

                // Get the entire line
                getline(file, line);

                // If the line is empty, this student has no courses
                if (line == "")
                {
                    cout << "Data contains Student with no courses." << endl;
                }

                // If the line is not empty
                else
                {
                    // Put the line in a stream
                    stringstream sstr(line);
                    
                    // Start with zero, no courses
                    int size = 0;
                    
                    // While there is still stuff in the stream
                    while(sstr.good())
                    {
                        // Create a substring up until the first comma
                        string substr;
                        getline(sstr, substr, ',');

                        // If the substring is empty, Break
                        if(substr == "")
                        {
                            continue;
                        }

                        // If the courses counter is 1, we are at the course name. Get it and add it to the proper place
                        if(counter == 1)
                        {
                            // Add A course to the student
                            students[StudentIndex].courseSize++;
                            students[StudentIndex].courses[size].CourseName = substr;
                            
                            // Increment counter by one
                            counter++;
                        }

                        // If the course counter is 2, we are at the percentage. Get it and add it to the proper place
                        else if(counter == 2)
                        {
                            // Add the percentage as a double to the student
                            students[StudentIndex].courses[size].percentage = stod(substr);

                            // Increment counter by one
                            counter++;
                        }
                        // If the courses counter is 3, We are at credit score
                        else if(counter == 3)
                        {
                            // add credit score to proper place
                            students[StudentIndex].courses[size].credit = stoi(substr);

                            // Reset courses counter
                            counter = 1;

                            // Increment size by 1
                            size++;
                        }
                        
                        // if courses counter is 0, add one and re-loop
                        else
                        {
                            counter++;
                        }

                    }
                    
                }

                // Logging that data has been read
                string log;
                stringstream buffer;
                buffer << "Read Data for students. This includes: \n" 
                << "\tName: " << students[StudentIndex].Name 
                << "\n\tCourses added: " << students[StudentIndex].courseSize;
                log = buffer.str();
                createLog(log);

                // Calculate GPA of current students
                CalculateGPA(students[StudentIndex]);
                
            }
            else
            {
                // add name to that students and increment array size
                getline(file, line);
                students[students[0].ArraySize++].Name = line;
            }
        }
    }

    // Give the user an Error message if Data has a formatting Issue
    catch(const std::exception& e)
    {
        cout << "Error occurred while reading Data. Please make sure Data is formatted Correctly.\n\n";
        cout << "Format: \n\nStudent Name\nCourse Name1,Grade1,Credit1,Course Name2,Grade2,Credit2....CreditN\nStudent Name\n....\n\nCourse lines can be left EMPTY if student has no courses Added.\n\nExiting Program...\n";
        exit(1);
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

    // Get a time string
    string timeString = timeStamp();

    // Add time to start of database
    file << timeString << endl;


    // Loop through students
    for(int i = 0; i < students[0].ArraySize; i++)
    {
        // Loop through students as if they consist of two lines
        for(int j = 0; j < 2; j++)
        {
            // if we at line 1, we are at name. Put the name in file and start a new line. Go to next loop
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
                    // Add comma after credit except if its the last one
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

    // Preparing report Variables
    int modifications = 0;
    int additions = 0;
    int deletions = 0;

    // Start a loop through the file
    while(getline(file, line))
    {
        // if added is in log, add additions
        if(line.find("Added") != string::npos)
        {
            additions++;
            continue;
        }
        
        // If deleted is detected, add deletions
        else if(line.find("Deleted") != string::npos)
        {
            deletions++;
            continue;
        }

        // if modified was detected, add modification
        else if(line.find("Modified") != string::npos)
        {
            modifications++;
            continue;
        }
    }
    
    // Close the file
    file.close();

    // Create a report file
    ofstream report;
    report.open("Data Files/Statistical Report.txt");

    // Timestamp String
    string reportTime = timeStamp();

    // Add information to the report in Tabular Format
    report << setw(40) << left << "Report Generated at:"  << setw(5) << reportTime << endl;
    report << "===================================================================" << endl;
    report << setw(40) << left << "Number of records: " << setw(5) << students[0].ArraySize << endl;
    report << setw(40) << left << "Date since last Update: " << setw(5) << dateModified << endl;
    report << setw(40) << left << "Number of Additions in total: " << setw(5) << additions << endl;
    report << setw(40) << left << "Number of Deletions in total: " << setw(5) << deletions << endl;
    report << setw(40) << left << "Number of Modifications in total: " << setw(5) << modifications << endl;

}

// Main menu
void mainMenu()
{
    cout << "============================== Student Database -- Menu ==============================" << endl;
    cout << "1 - Add Student." << endl;
    cout << "2 - Remove Student." << endl;
    cout << "3 - Select Student." << endl;
    cout << "4 - Display All Students." << endl;
    cout << "5 - Generate Report." << endl;
    cout << "6 - Exit." << endl;
    cout << "======================================================================================";
}

// Function to add students
void addStudent(Student students[])
{
    // Check if students are at max number
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
    int Index = students[0].ArraySize;
    students[0].ArraySize++;
    students[Index].Name = name;

    // Start student with no courses and no GPA
    students[Index].courseSize = 0;
    students[Index].GPA = 0;
    
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
                addCourse(students, i, Index);
            }
            
            // Tell User that the courses were added
            cout << "Courses Added Successfully.\n\n";

            // Calculate the GPA of that student
            CalculateGPA(students[Index]);
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
    
    // Logging Adding Student
    stringstream buffer;
    buffer << "New Student Added.\n";
    buffer << "\tStudent Name: " << students[Index].Name << endl;
    buffer << "\tCourses added: " << students[Index].courseSize;

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

    // Get course index
    int courseIndex = students[index].courseSize;

    // Add one Course
    students[index].courseSize++;

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
    double percentage = getDouble(prompt);

    // Make sure percentage is within Appropriate Range
    while(percentage < 0 || percentage > 100)
    {
        cout << "Input must be between 0 and 100" << endl;
        percentage = getDouble(prompt);
    }
   
    // Prepare prompt for credit
    buffer.str(string());
    buffer << "Enter course number " << i + 1 << "'s Credit Hours: ";
    prompt = buffer.str();

    // Ask for credit
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
            string topOfMenu = "============================== " + students[index].Name + " is Selected ==============================";
            cout << topOfMenu << endl;
            cout << "1 - Display Student Information\n";
            cout << "2 - Add Courses to Student.\n";
            cout << "3 - Remove Course from Student.\n";
            cout << "4 - Edit a course for Student.\n";
            cout << "5 - Delete Student.\n";
            cout << "6 - Back to main Menu.\n";
            for(int i = 0; i < topOfMenu.length(); i++)
            {
                cout << "=";
            }
            cout << endl; 
            
            // Get the user's Choice from the menu
            int choice = getInt("\nPlease Select an Item from the menu: ");

            // Display student Information
            if(choice == 1)
            {
                displayStudent(students[index]);
            }
            
            // Add a course to the students
            else if(choice == 2)
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

                // Mark Record as modified and log it
                stringstream buffer;
                string log;
                buffer << "Modified Courses for Student: " << students[index].Name;
                buffer << " - Old Course Total:  " << CourseSize;
                buffer << " - New Course Total: " << students[index].courseSize;
                log = buffer.str();
                createLog(log);
            }

            // Remove a course
            else if(choice == 3)
            {
                // Get course index
                int courseIndex = searchCourse(students[index].courses, students[index].courseSize);
                if(courseIndex != -1)
                {
                    // Get Size of courses
                    int size = students[index].courseSize;
                    
                    // Get course name and save it
                    string courseName = students[index].courses[courseIndex].CourseName;

                    // Get course and delete it
                    for (int j = courseIndex; j < size; j++)
                    {
                        students[index].courses[j] = students[index].courses[j+1];
                    }
                    students[index].courseSize = size - 1;

                    // Tell User
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
            else if(choice == 4)
            {
                // Get course
                int courseIndex = searchCourse(students[index].courses, students[index].courseSize);

                // If Found
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
                        string topOfMenu = "============================= " + students[index].courses[courseIndex].CourseName + " is selected =============================";
                        cout << topOfMenu << endl;

                        // Present current course information
                        cout << "Percentage: " << students[index].courses[courseIndex].percentage << endl;
                        cout << "Credit: " << students[index].courses[courseIndex].credit << endl << endl; 
                        cout << "1 - Change Course Name.\n";
                        cout << "2 - Change Course Grade.\n";
                        cout << "3 - Change Course Credit.\n";
                        cout << "4 - Return to Previous Menu\n";
                        for(int i = 0; i < topOfMenu.length(); i++)
                        {
                            cout << "=";
                        }
                        cout << "\n\n";
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
                            // Get Credit
                            int credit = getInt("Please Enter New Credit Hours: ");

                            // Validate it
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

                    // If the course was modified, Log it.
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

            // If user wants to delete selected student
            else if(choice == 5)
            {
                removeStudent(students, index);
                break;
            }

            // Else if user wants to return to main menu
            else if(choice == 6)
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
    // If index was not passed (Default value), Search for student they want to delete
    if(index == -2)
    {
        index = searchStudents(students);
    }
    

    // If index was given
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
    // Check if there are students in Array
    int size = students[0].ArraySize;

    // If there are no students, return -1
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
        cout << "=============================================================" << endl;
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

        // Return selected Index 
        return index[id];
    }

    // If no students were found, inform user
    else
    {
        cout << "No students found with this name. Please make sure the name is spelled correctly." << endl;
        return -1;
    }

    // If everything happened to find the student and they were still not found, return -1
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
        cout << "==================================================================================" << endl;
        cout << setw(5) << left << "ID";
        cout << setw(20) << "Courses";
        cout << setw(20) << "Percentage";
        cout << setw(10) << "Credit";
        cout << endl;

        // Loop through index and display all found courses
        for(int i = 0; i < index.size(); i++)
        {
            cout << setw(5) << left << i;
            cout << setw(20) << courses[index[i]].CourseName;
            cout << setw(20) << courses[index[i]].percentage;
            cout << setw(10) << courses[index[i]].credit;
            cout << endl;
        }
        cout << "==================================================================================" << endl;
        // Ask user for ID and validate it
        int id = getInt("Please Select by ID: ");

        // Validate ID
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
        cout << "No Courses found with this name. Please make sure the Course name is spelled correctly." << endl;
        return -1;
    }

    // If all else fails, return -1. Course was not found
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
    cout << "============================== Displaying Students ===================================" << endl;

        // Loop through all students and Display appropriate information in appropriate Columns
        for(int i = 0; i < size; i++)
        {
            // Display Column Names
            cout << setw(20) << left << "Name";
            cout << setw(30) << "Courses";
            cout << setw(10) << "Percent";
            cout << setw(5) << "Credit"; 
            cout << endl;

            // Display name in first column
            cout << setw(20) << students[i].Name;

            // If student has no courses, display that
            if(students[i].courseSize == 0)
            {
                cout << setw(30) << "Student Has No courses Added";
            }

            // IF student does have courses
            for(int j = 0; j < students[i].courseSize; j++)
            {
                // If first loop, display course information normally
                if(j == 0)
                {
                    cout << setw(30) << students[i].courses[j].CourseName 
                    << setw(10) << students[i].courses[j].percentage 
                    << setw(5) << students[i].courses[j].credit << endl;
                }

                // Else
                else
                {   
                    // Add placeholder instead of student name
                    cout << setw(20)  << left << ""

                    // Display Courses 
                    << setw(30) << students[i].courses[j].CourseName 
                    << setw(10) << students[i].courses[j].percentage 
                    << setw(5) << students[i].courses[j].credit << endl;
                }
            }
            // End line
            cout << endl 
            
            // Place holder instead of name
            << setw(20) << left << ""

            // Display GPA 
            << setw(10) << "GPA: " << students[i].GPA 

            // End Section
            << endl << "======================================================================================" << endl;
        }
    
    // End line twice
    cout << "\n\n";
}

// Display Selected Student
void displayStudent(Student student)
{
    // Display students in Tabular Format
    cout << "============================== Displaying Students ===================================" << endl;
    cout << setw(20) << left << "Name";
    cout << setw(30) << "Courses";
    cout << setw(10) << "Percent";
    cout << setw(5) << "Credit"; 
    cout << endl;

    // Display Student name in appropriate column
    cout << setw(20) << student.Name;
    if(student.courseSize == 0)
    {
        cout << setw(30) << "Student Has No courses Added";
    }

    // Loop through all the courses the student has and display them
    for(int j = 0; j < student.courseSize; j++)
    {
        // Display Courses Appropriately.
        if(j == 0)
        {
            cout << setw(30) << student.courses[j].CourseName 
            << setw(10) << student.courses[j].percentage 
            << setw(5) << student.courses[j].credit << endl;
        }
        else
        {
            cout << setw(20)  << left << "" 
            << setw(30) << student.courses[j].CourseName 
            << setw(10) << student.courses[j].percentage 
            << setw(5) << student.courses[j].credit << endl;
        }
    }
    // End line
    cout << endl 

    // Display GPA appropriately
    << setw(20) << left << "" 
    << setw(10) << "GPA: " << student.GPA 
    << endl << "======================================================================================" << endl;
        
    cout << "\n\n";
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
            // Display Prompt
            cout << Prompt;

            // Get User input as string 
            getline(cin, choice);

            // Convert String to Integer
            realChoice = stoi(choice);

            // Exit loop
            break;
            
        }

        // Tell user it must be a number
        catch(const std::exception& e)
        {
            cout << "Input must be a number. Try again.\n";
            continue;
        }
    }
    
    // Return User input
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
            // Display Prompt
            cout << Prompt;

            // Get input as string 
            getline(cin, choice);

            // Convert to double
            realChoice = stod(choice);
            break;
            
        }

        // Tell user it must be a number
        catch(const std::exception& e)
        {
            cout << "Input must be a number. Try again.\n";
            continue;
        }
    }

    // Return converted input
    return realChoice;
}

// Sorting Function
bool compareByCharacter(const Student &a, const Student &b)
{
    return tolower(a.Name[0]) < tolower(b.Name[0]);
}

// Sorting function for courses
bool compareByCharacterCourses(const Grades &a, const Grades &b)
{
    return tolower(a.CourseName[0]) < tolower(b.CourseName[0]);
}