// Including
#include <iostream>

// Namespace
using namespace std;

// Prototypes
void printArray(int array[], int SIZE, int tableno);
void multiplication_Table(int arr[],int size,int tableNo);

// Main function
int main(int argc, char const *argv[])
{
    // Create array
    int array[10];

    // Get number to create table
    cout << "Enter Multiplication table number: ";
    int tableno;
    cin >> tableno;

    // Call function to do multiplication
    multiplication_Table(array, 10, tableno);

    // Print the array
    printArray(array, 10, tableno);

    return 0;
}

// Multiplication table creator
void multiplication_Table(int arr[],int size,int tableNo)
{
    // Loop through array and create multiplication table based on user
    for(int i = 0; i < size; i++)
    {
        arr[i] = (i+1) * tableNo;
    }
}

// Function to print a string array
void printArray(int array[], int SIZE, int tableno)
{
    // Print multiplication table
    for(int i = 0; i < SIZE; i++)
    {
        cout << tableno << " x " << i+1 << " = " << array[i] << "\n";
    }
    cout << endl;
}

