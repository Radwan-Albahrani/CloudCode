#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    // Define Size
    int SIZE = 0;

    // Get size by the user
    cout << "Enter Array Size: ";
    cin >> SIZE;

    // Define array
    int array[SIZE];

    // Get array values from the user
    cout << "Enter " << SIZE << " Values: ";
    for(int i = 0; i < SIZE; i++)
    {
        cin >> array[i];
    }

    // print Unsorted Array
    cout << "Unsorted array: " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    //Sort Array
    sort(array, array + SIZE);

    // Print Sorted array
    cout << "Sorted array: " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    return 0;
}