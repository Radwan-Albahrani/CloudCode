#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Initialize Array
    int array[10];

    // Ask user for input
    cout << "Enter 10 items in ascending order: ";
    for(int i = 0; i < 10; i++)
    {
        cin >> array[i];
    }

    //Check if array is ordered using bool variable
    bool isOrderedAscending = true;
    bool isOrderedDescending = true;
    for(int i = 0; i < 9; i++)
    {
        if(array[i] > array[i+1])
        {
            isOrderedAscending = false;
        }
        if(array[i] < array[i+1])
        {
            isOrderedDescending = false;
        }
    }

    // Print Results
    if(isOrderedAscending)
    {
        cout << "The array is ordered Ascendingly";
    }
    else if(isOrderedDescending)
    {
        cout << "The array is Ordered Decendingly";
    }
    else
    {
        cout << "The Array is not Ordered";
    }
    return 0;
}
