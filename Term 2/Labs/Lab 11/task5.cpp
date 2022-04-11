// Including
#include <iostream>

// Namespace
using namespace std;

// Prototypes:
void reserve(bool **arr,int rows,int cols);
void available(bool **arr,int rows,int cols);
void display(bool **arr,int rows,int cols);

int main(int argc, char const *argv[])
{
    // Define rows and columns
    int rows, cols;

    // Get rows and columns
    cout << "How many rows are in the plane: ";
    cin >> rows;
    cout << "How many seats per row: ";
    cin >> cols;
    
    // Create array
    bool ** arrayPtr = new bool*[rows];

    // Make it 2D
    for(int i = 0; i < rows; i++)
    {
        arrayPtr[i] = new bool[cols];
    }

    // Empty it
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            arrayPtr[i][j] = 0;
        }
        cout << endl;
    }

    // Start the main loop
    while(1)
    {
        // Present menu
        cout << "==================Menu==================" << endl;
        cout << "1 - reserve a seat" << endl;
        cout << "2 - display available seats" << endl;
        cout << "3 - display all seats in the plane" <<  endl;
        cout << "4 - Exit" << endl;

        // Get choice
        cout << endl << "Please select from the menu: ";
        int choice;
        cin >> choice;

        // Flag
        int flag = 0;

        // Apply based on choice
        switch (choice)
        {
            case 1:
                reserve(arrayPtr, rows, cols);
                break;
            case 2:
                available(arrayPtr, rows, cols);
                break;
            case 3:
                display(arrayPtr, cols, rows);
                break;
            case 4:
                flag = -1;
                break;
            default:
                cout << "Not a choice" << endl;
                break;
        }

        // Exit based on flag
        if(flag == -1)
        {
            break;
        }

    }

    // Clean up
    for(int i = 0; i < rows; i++)
    {
        delete[] arrayPtr[i];
    }
    delete[] arrayPtr;
    
    return 0;
}

// Reserve a seat
void reserve(bool **arr,int rows,int cols)
{
    // Get the seat
    int seat1, seat2;
    cout << "Which seat would you like to reserve? [rows] [cols]: ";
    cin >> seat1 >> seat2;

    // Reserve the seat
    arr[seat1 - 1][seat2 - 1] = true;

    cout << "Seat Reserved Successfully" << endl;
}

// Count available seats
void available(bool **arr,int rows,int cols)
{
    int count = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(arr[i][j] == 0)
            {
                count++;
            }
        }
    }

    cout << "Available Seats: " << count << endl;
}

// Display
void display(bool **arr,int rows,int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}