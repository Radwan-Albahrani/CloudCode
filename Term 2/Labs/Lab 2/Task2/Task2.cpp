#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Get array size from user
    int SIZE = 0;
    cout << "Enter Array Size: ";
    cin >> SIZE;

    // Make Array
    int array[SIZE];

    // Get Array Elements from user
    cout << "Enter " << SIZE << " Elements for the array: ";
    for(int i = 0; i < SIZE; i++)
    {
        cin >> array[i];
    }

    // Check if user wants to rotate right or left
    char answer;
    cout << "Do you want to shift right or left? (R/L): ";
    cin >> answer;

    // Check number of rotations
    int numberOfShifts = 0;
    cout << "How many times do you want to shift: ";
    cin >> numberOfShifts;

    // Get new values for the shift
    int arrayNEW[numberOfShifts];
    cout << "Enter " << numberOfShifts << " Values to insert into array: ";
    for(int i = 0; i < numberOfShifts; i++)
    {
        cin >> arrayNEW[i];
    } 

    // Perform Rotation
    // If rotation is right
    if (answer == 'R')
    {
        // Loop for the number of shifts requested
        for(int i = 0; i < numberOfShifts; i++)
        {
            // Loop from the end of the array to the start of the array
            for(int j = SIZE - 1; j > 0; j--)
            {
                // Take the current element and replace it with the previous element
                array[j] = array[j - 1];
            }
            array[0] = arrayNEW[i];
            
        }
    }

    // Do the same thing for rotating left
    else if(answer == 'L')
    {
        // Loop for the number of rotations requested
        for(int i = 0; i < numberOfShifts; i++)
        {
            // Loop from beginning to end
            for(int j = 0; j < SIZE; j++)
            {
                // Take the next element and put it in current element
                array[j] = array[j + 1];
            }
            array[SIZE - 1] = arrayNEW[i];
        }
    }

    // Print out Shifted completed array
    cout << endl << "Shifted array is: " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << array[i] << "\t";
    }
    return 0;


}
