#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Get array ROWS from user
    int ROWS = 0;
    cout << "Enter Array ROWS: ";
    cin >> ROWS;

    int COLS = 0;
    cout << "Enter Array COLUMNS: ";
    cin >> COLS;
    // Make Array
    int array[ROWS][COLS];

    // Get Array Elements from user
    cout << "Enter " << ROWS * COLS << " Elements for the array: ";
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cin >> array[i][j];
        }
        
    }

    // Check if user wants to rotate right or left
    char answer;
    cout << "Do you want to rotate up or down? (U/D): ";
    cin >> answer;
    // Select column to rotate:
    int col = 0;
    // keep asking until column within parameters
    do
    {
        cout << "Select a column to rotate: ";
        cin >> col;
        col = col - 1;
    
        // Make sure the colum is within the parameters
        if(col >= COLS)
        {
            cout << "Invalid number. Maximum number is: " << COLS << endl;
        }
    } while(col >= COLS);

    // Check number of rotations
    int numberOfRotations = 0;
    cout << "How many times do you want to rotate: ";
    cin >> numberOfRotations;

    // Perform Rotation
    // If rotation is down
    if (answer == 'D')
    {
        // Loop for the number of rotations requested
        for(int i = 0; i < numberOfRotations; i++)
        {
            // Save the last element
            int temp = array[ROWS - 1][col];
            // Loop from the end of the array to the start of the array
            for(int j = ROWS - 1; j > 0; j--)
            {
                // Take the current element and replace it with the previous element
                array[j][col] = array[j - 1][col];
            }
            array[0][col] = temp;
        }
    }

    // Do the same thing for rotating up
    else if(answer == 'U')
    {
        // Loop for the number of rotations requested
        for(int i = 0; i < numberOfRotations; i++)
        {
            // Save the first element
            int temp = array[0][col];
            // Loop from beginning to end
            for(int j = 0; j < ROWS; j++)
            {
                // Take the next element and put it in current element
                array[j][col] = array[j + 1][col];
            }
            array[ROWS - 1][col] = temp;
        }
    }

    // Print out rotated completed array
    cout << endl << "Rotated array is: " << endl;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cout << array[i][j] << '\t';
        }
        cout << "\n";
    }
    return 0;


}
