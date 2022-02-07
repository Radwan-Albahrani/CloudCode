#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    // Initialize variables.
    int STUDENTS = 10;
    int MARKS = 5;

    // Initialize arrays
    double grades[11][6];
    int minimumsPerStudent[10];
    int maximumPerStudent[10];
    int minimumPerCourse[5];
    int maximumPerCourse[5];

    // Introduce Program
    cout << "This program will calculate averages, min, max, for 10 different students on 5 different courses. \n\n";

    // Start getting scores for each student
    for(int i = 0; i < STUDENTS; i++)
    {
        // Tell user to enter 5 grades
        cout << "Enter 5 Grades for student number: " << i + 1 << endl;

        // initialize variables to catch the sum max and min per student
        double sum = 0;
        double max = 0;
        double min = 100;

        // Loop through each student and get scores.
        for(int j = 0; j < MARKS; j++)
        {
            // variable to validate any entered grades
            double grade = 0;
            // Start a loop
            do
            {
                // Get grade
                cin >> grade;
                
                // Validate it and if not valid, reloop
                if(grade > 100 && grade < 0)
                {
                    cout << grade << " Was not accepted (must be between 0 and 100): \n";
                    cout << "you have to enter " << j + 1 << "grades for this student: ";
                }

            } while (grade > 100 && grade < 0);
            
            // Add Validated grade to array
            grades[i][j] = grade;
            
            // Add it to a sum for averaging later
            sum += grade;

            // Find out maximum and minimum for the current student
            if(grade > max)
            {
                max = grade;
                
            }
            if(grade < min)
            {
                min = grade;
            }
        }
        // Add maximum and minimum to arrays
        maximumPerStudent[i] = max;
        minimumsPerStudent[i] = min;

        // Calculate average per student.
        double average = sum / 5.0f;

        // Add average to last part of the current student
        grades[i][5] = average;
    }

    // Calculate average per course
    for(int i = 0; i < MARKS; i++)
    {
        // Variables for average min and max
        double sum = 0;
        double min = 100;
        double max = 0;

        // Loop through columns
        for(int j = 0; j < STUDENTS; j++)
        {
            // get current grade
            double grade = grades[j][i];
            
            // Sum it
            sum += grade;
            
            // Figure out if its min or max
            if(grade > max)
            {
                max = grade;
            }
            if(grade < min)
            {
                min = grade;
            }
        }
        
        // Add max and min
        maximumPerCourse[i] = max;
        minimumPerCourse[i] = min;

        // Get average
        double average = sum / 10.0f;

        // Add average to array
        grades[10][i] = average;
    }

    // calculate average for averages
    double sum = 0;
    for(int i = 0; i < 10; i++)
    {
        
        sum += grades[i][5];
    }
    double average = sum / 10.0f;
    grades[10][5] = average;

    // Print out data about averages
    cout << "Data successfully added. Displaying results: \n";
    cout << "student\tmark1\tmark2\tmark3\tmark4\tmark5\taverage" << endl;
    for(int i = 0; i < 11; i++)
    {
        if(i != 10)
        {
            cout << i + 1 << "\t";
        }
        else
        {
            cout << "average ";
        }
        for(int j = 0; j < 6; j++)
        {
            cout << grades[i][j] << "\t";
        }
        cout << endl;
    }

    // Print out max and minimum data in Tabular Format for each student
    cout << "\n\n" << "Now we will display maximum and minimum data per student." << endl;
    cout << "Student\tmax\tmin" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << i+1 << "\t" << maximumPerStudent[i] << "\t" << minimumsPerStudent[i] << endl;
    }
    
    // Print out max and min data per course for each course
    cout << "\n\n" << "Now we will display maximum and minimum per course." << endl;
    cout << "Course\tmax\tmin" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << "\t" << maximumPerCourse[i] << "\t" << minimumPerCourse[i] << endl;
    }

    return 0;
    
}


