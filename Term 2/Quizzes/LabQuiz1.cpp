/*
Fundamentals of Programming

Lab Quiz – 1

Question: Write a program that asks user to input ten integers in an array. Add elements of array as given below in a second array of size ten:

Sum 1 = first element

Sum 2 = first element + second element

Sum 3 = first element + second element + third element

….

Sum 10 = first element + second element + third element + …. + tenth element

Then find the maximum sum and minimum sum among these sums and display them.

*/


#include <iostream>

using namespace std;
void printArray(int array[], int SIZE);

int main(int argc, char const *argv[])
{
    // Initialize arrays
    int array[10];
    int arraySums[10];

    // Request array items from user
    cout << "Please input 10 elements for the array: ";
    for(int i = 0; i < 10; i++)
    {
        cin >> array[i];
    }

    // Calculate required sums and add them to second array
    for(int i = 0; i < 10; i++)
    {
        int sum = 0;
        for(int j = i; j >=0; j--)
        {
            sum += array[j];
        }
        arraySums[i] = sum;
    }

    // Print out Original Array
    cout << "Original Array: ";
    printArray(array, 10);

    // Print out Sum arrays
    cout << "Sum Array: ";
    printArray(arraySums, 10);

    // Initialize maximum and minimum
    int max = -999999999;
    int min = 999999999;

    // Find maximum and minimum sum
    for(int i = 0; i < 10; i++)
    {
        if(arraySums[i] > max)
        {
            max = arraySums[i];
        }
        if(arraySums[i] < min)
        {
            min = arraySums[i];
        }
    }

    // Print out maximum and minimum Sum
    cout << "Minimum Sum: " << min << endl;
    cout << "Maximum Sum: " << max << endl;

    return 0;
}

// Function to print arrays
void printArray(int array[], int SIZE)
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}