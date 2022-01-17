#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Initialize two arrays
    int arrayA[3][3];
    int arrayB[3][3];

    // Introduce the program
    cout << "This program will multiply two 3 x 3 arrays and give you the products: " << endl;
    
    // Request input of first array
    cout << "Enter first array: " << endl;
    for (int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arrayA[i][j];
        }
    }

    // Request input of second array
    cout << "Enter second array: " << endl;
    for (int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arrayB[i][j];
        }
    }

    // Multiply array and add it to a third matrix
    int product[3][3];

    for(int i = 0; i < 3; i++)
    {
        
        for(int j = 0; j < 3; j++)
        {
            int current_product = 0;
            for(int k = 0; k < 3; k++)
            {
                current_product += arrayA[i][k] * arrayB[k][j];
            }
            product[i][j] = current_product;
        }
    }

    cout << "Printing Result: " << endl;
    for (int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
