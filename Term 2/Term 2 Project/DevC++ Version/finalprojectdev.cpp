// Including
#include <iostream>
#include <filesystem>

// Namespace
using namespace std;

// Prototypes and structs
#include "Prototypes.h"


// Main function
int main(int argc, char const *argv[])
{

    // Create a students Array.
    Student students[100];
    
    // Read all students from database, if exists
    ReadStudentsFromFile(students);

    // Main program loop
    while (true)
    {
        // Display menu
        mainMenu();

        // Get choice from user
        int choice = getInt("\n\nPlease Select an Item from the menu: ");
        
        // Switch statement for choices
        switch (choice)
        {
            case 1:
                addStudent(students);
                break;
            case 2:
                removeStudent(students);
                break;
            case 3:
                selectStudent(students);
                break;
            case 4:
                displayAllStudents(students);
                break;
            case 5:
                GenerateReport(students);
                cout << "Report Generated Successfully\n";
                break;
            case 6:
                break;
            default:
                cout << "Selected choice not in menu. Please select from the menu" << endl;
                break;
        }

        // If user choses to exit the program
        if(choice == 6)
        {
            // Quickly Sort by First letter.
            sort(students, students + students[0].ArraySize, compareByCharacter);

            // Update database if necessary
            WriteStudentsToFile(students, isModified);

            // Exit Program
            break;
        }

    }
    return 0;
}
