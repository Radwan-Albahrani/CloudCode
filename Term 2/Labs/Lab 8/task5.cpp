// Including and namespace
#include <iostream>
#include <string>
using namespace std;

// struct
struct student
{
    string name;
    string ID;
    string major;
    int mark;
};

// Getinfo Function
double getInfo(student students[], int size);

// Print info function
void printInfo(student students[], int size, double average);

// Letter grade function
char letterGrade(int mark);

// MAin function
int main(int argc, char const *argv[])
{
    // Get size from student
    int size;
    cout << "How many students: ";
    cin >> size;

    // Delcare studnet array
    student students[size];

    // Get info and get average
    double average = getInfo(students, size);

    // Print the info
    printInfo(students, size, average);
    
    
    return 0;
}

double getInfo(student students[], int size)
{
    // Declare average
    double average = 0;

    // Loop through the size and get all the info while adding to average
    for (int i = 0; i < size; i++)
    {
        cout << "Enter student " << i + 1 << " Name: ";
        cin >> students[i].name;
        cout << "Enter student " << i + 1 << " ID: ";
        cin >> students[i].ID;
        cout << "Enter student " << i + 1 << " major: ";
        cin >> students[i].major;
        cout << "Enter student " << i + 1 << " grade: ";
        cin >> students[i].mark;
        average += students[i].mark;
    }

    // Calculate and return average
    average = average / size;
    return average;
}

void printInfo(student students[], int size, double average)
{
    // Print each student information and their letter grade
    for(int i = 0; i < size; i++)
    {
        cout << "\n\nStudent Name: " << students[i].name << endl;
        cout << "Student ID: " << students[i].ID << endl;
        cout << "Student major: " << students[i].major << endl;
        cout << "Student Grade: " << students[i].mark << endl;
        int mark = students[i].mark;
        char lettergrade = letterGrade(mark);
        cout << "Letter Grade: " << lettergrade << "\n\n";
        
    }

    // Print the class average letter grade
    cout << "Class Average grade: " << letterGrade(average) << endl;
}

char letterGrade(int mark)
{
    // Determine letter grade based on mark
    char lettergrade;
    if(mark >= 90 && mark <= 100)
    {
        lettergrade = 'A';
    }
    else if(mark >= 80 && mark < 90)
    {
        lettergrade = 'B';
    }
    else if(mark >= 70 && mark < 80)
    {
        lettergrade = 'C';
    }
    else if(mark >= 60 && mark < 70)
    {
        lettergrade = 'D';
    }
    else
    {
        lettergrade = 'F';
    }
    return lettergrade;

}