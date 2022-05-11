// Including
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // Ask user for array size
    int arraySize;
    cout << "Enter The number of students in class: ";
    cin >> arraySize;

    // Create dynamic array for names
    string * names = new string[arraySize];

    // Create dynamic array for grades
    float * grades = new float[arraySize];


    // Prepare average sum
    float sum = 0;
    // Loop through and get all student names and grades
    for(int i = 0; i < arraySize; i++)
    {
        cout << "Enter student number " << i + 1 << "'s Name: ";
        cin >> names[i];
        cout << "Enter student number " << i + 1 << "'s Grade: ";
        cin >> grades[i];

        // Add to sum
        sum += grades[i];
    }

    // Calculate average
    float average = sum/arraySize;

    // Print out class average
    cout << "The class average is: " << average << endl;

    // Print out failing students
    for(int i = 0; i < arraySize; i++)
    {
        if(grades[i] <= average)
        {
            cout << names[i] << " Needs extra courses. Grade: " << grades[i] << endl;
        }
    }

    // Delete arrays
    delete[] names;
    delete[] grades;


    return 0;
}
