#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Initialize size
    int SIZE = 0;

    // Request size from user
    cout << "Enter the size of your array: ";
    cin >> SIZE;

    // create two arrays, original and reversed
    int arrayOriginal[SIZE];
    int ArrayReversed[SIZE];

    // Request values of original from user
    cout << "Enter the " << SIZE <<" Values of your array: ";
    
    // Loop as many times as size 
    for(int i = 0, j = SIZE - 1; i < SIZE; i++, j--)
    {
        // Get original value
        cin >> arrayOriginal[i];
        
        // Reverse it
        ArrayReversed[j] = arrayOriginal[i]; 
    }

    // Print reversed array
    cout << "Reversed array: " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << ArrayReversed[i] << " ";
    }

    // End program
    cout << endl;
    return 0;
}
