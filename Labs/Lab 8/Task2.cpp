#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Defining Variables and arrays
    const int SIZE = 5;
    int arrA[SIZE];
    int arrB[SIZE];
    int arrC[SIZE * 2];

    // Getting the values of the first array
    cout << "Enter 5 Values of the first Array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> arrA[i];
    }

    // Getting the values of the second array
    cout << "Enter 5 Values of the second Array: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> arrB[i];
    }

    // Combining Arrays
    for(int i = 0; i < SIZE * 2; i++)
    {
        if(i < SIZE)
        {
            arrC[i] = arrA[i];
        }
        else
        {
            arrC[i] = arrB[i - SIZE];
        }
    }

    // Printing out combined Array
    cout << "The combined array is: " << endl;
    for(int i = 0; i < SIZE * 2; i++)
    {
        cout << arrC[i] << "\t";
    }
    cout << endl;
    return 0;
}
