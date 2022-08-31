#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    // Defining Variables
    int SIZE = 0;
    double average;
    int sum = 0;
    int minimum = 0;
    int maximum = 0;

    // Getting Array Size
    cout << "Enter the size of the array: ";
    cin >> SIZE;

    // Defining Array
    int numbers[SIZE];

    // Getting all numbers from user
    cout << "Enter the [" << SIZE << "] numbers: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> numbers[i];
    }
    // Printing out all inputted numbers, calculating sum.
    cout << "There are " << SIZE << " Values which are: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << numbers[i] << "\t";
        sum += numbers[i];
    }
    // new line
    cout << endl;
    
    // Calculating Average
    average = sum / SIZE;

    // Calculating maximum and minimum
    maximum = *max_element(numbers, numbers + SIZE);
    minimum = *min_element(numbers, numbers + SIZE);

    // Printing out values
    cout << "The sum of all the values is: " << sum << endl;
    cout << "The Average of the values is: " << average << endl;
    cout << "The maximum Value is: " << maximum << endl;
    cout << "The minimum Value is: " << minimum << endl;

    
    return 0;
}
