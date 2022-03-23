#include <iostream>
#include <string>
using namespace std;

// Grades struct
struct Grades
{
    double percentage;
    int credit = 0;
};


// Student Struct
struct Student
{
    string Name;
    Grades courses[100];
    double GPA;
};

// Function to calculate GPA
void CalculateGPA(Student&, int);

// Main function
int main(int argc, char const *argv[])
{
    // Necessary counters
    int studentCounter = 0;
    int coursePerStudent[100] = {0};
    
    // Testing phase: Create students and add random info
    Student students[100];
    students[0].Name = "Ahmad";
    students[0].courses[0].percentage = 85;
    students[0].courses[0].credit = 3;
    
    // Counter for how many students added and their courses
    studentCounter++;
    coursePerStudent[0]++;

    // Calculate GPA of students
    CalculateGPA(students[0], coursePerStudent[0]);

    // Print GPA
    cout << students[0].GPA;
    return 0;
}

// Function to calculate GPA by reference
void CalculateGPA(Student& students, int size)
{
    // Prepare total points and total credit houts
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
}