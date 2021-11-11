#include <iostream>

using namespace std;
void bubblesort(int *a, size_t n);

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
    bubblesort(array, SIZE);

    // Print Sorted array
    cout << "Sorted array: " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    return 0;
}




void bubblesort(int *a, size_t n)
{
    // Loop through pointer like its a 1d array with max length equal to number of elements in sales
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            // Bubble sorter
            if (a[i] > a[j]) 
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}