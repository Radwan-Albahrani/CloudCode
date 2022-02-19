#include <iostream>
#include <string>

using namespace std;
void printArray(string array[], int SIZE);

int main(int argc, char const *argv[])
{
    // Define Size
    int SIZE;
    
    // Ask User for size of array. it must be even
    cout << "Enter Size of Array (Must be Even): ";
    do
    {
        cin >> SIZE;
        if (SIZE % 2 != 0)
        {
            cout << "Number MUST BE even. Try again: ";
        }

    }while(SIZE % 2 != 0);

    // Create two arrays with the size provided
    string names[SIZE];
    string jobs[SIZE];

    // Get input for the arrays
    for(int i = 0; i < SIZE; i++)
    {
        string name;
        string job;
        cout << "Enter Name #" << i+1 << ": ";
        cin >> name;
        cout << "Enter Job for " << name << ": ";
        cin >> job;
        names[i] = name;
        jobs[i] = job;
        cout << endl;
    }

    // Define number of rotations for the user and get it
    int numberOfRotations;
    cout << "Enter number of Rotations: ";
    cin >> numberOfRotations;

    // Print normal array before rotation
    cout << "\n\nArray before rotation: " << endl;
    printArray(names, SIZE);
    
    // Loop for the number of rotations requested
    for(int i = 0; i < numberOfRotations; i++)
    {
        // Save the last element
        string temp = names[SIZE - 1];
        string temp2 = jobs[SIZE - 1];
        // Loop from the end of the array to the start of the array
        for(int j = SIZE - 1; j > 0; j--)
        {
            // Take the current element and replace it with the previous element
            names[j] = names[j - 1];
            jobs[j] = jobs[j-1];
        }
        // Insert last element into first element
        names[0] = temp;
        jobs[0] = temp2;
    }
    
    // Print array after rotation
    cout << "\nArray After Rotation: " << endl;
    printArray(names, SIZE);

    // Select winner
    cout << "The selected element is at index: " << SIZE/2 << endl;

    // Print winner and his job
    cout << "The winner is: " << names[SIZE/2] << endl;
    cout << "The job of the winner is: " << jobs[SIZE/2] << endl;


    return 0;
}

// Function to print a string array
void printArray(string array[], int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
