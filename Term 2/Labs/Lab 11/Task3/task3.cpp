// Including
#include <iostream>

// Namespace
using namespace std;

// Prototypes
int *Array(int arraySize);
int oddSum(int * ArrayPtr, int ArraySize);
// main function
int main(int argc, char const *argv[])
{
    // Define array Size
    int arraySize;
    cout << "Enter Array Size: ";
    cin >> arraySize;

    // Get an array of that size and fill it
    int *newArray = Array(arraySize);
    cout << "Enter " << arraySize << " Values for the array: ";
    for (size_t i = 0; i < arraySize; i++)
    {
        cin >> newArray[i];
    }
    
    // Print out the odd sum of that array
    cout << "The Odd sum of that array is: " << oddSum(newArray, arraySize) << endl;
    return 0;
}

// Function to create a new dynamic array
int *Array(int arraySize)
{
    // Create dynamic array
    int * array = new int[arraySize];

    // Return array pointer
    return array;
}

// Function to find the odd sum
int oddSum(int * ArrayPtr, int ArraySize)
{
    // Get the odd sum
    int sum = 0;
    for (size_t i = 1; i < ArraySize; i+= 2)
    {
        sum += ArrayPtr[i];
    }

    // Return that sum
    return sum;
    
}