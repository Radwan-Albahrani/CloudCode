// Including
#include <iostream>

// Namespace
using namespace std;

// Defining a new type
typedef double* arrayPtr;

// Prototypes
void fillarray(arrayPtr cost, arrayPtr cups, int arraysize);
double calculateTotalPrice(arrayPtr cost, arrayPtr cups,int arraySize);

int main(int argc, char const *argv[])
{
    // Create two dynamic arrays with size 7
    int arraySize = 7;
    arrayPtr cost = new double[arraySize];
    arrayPtr cups = new double[arraySize];

    // Fill the arrays
    fillarray(cost, cups, arraySize);

    // Calculate the cost
    double total = calculateTotalPrice(cost, cups, arraySize);
    cout << "Total Cost: " << total << " SR";

    // Free up memory
    delete[] cost, cups;
    return 0;
}

// Function to fill the arrays
void fillarray(arrayPtr cost, arrayPtr cups, int arraysize)
{
    // Fill in the arrays
    for(int i = 0; i < arraysize; i++)
    {
        cout << "---------Day " << i + 1 << "---------"<<endl;
        cout << "Number of Cups: ";
        cin >> cups[i];
        cout << "Cost: ";
        cin >> cost[i];
    }
}

// Function to calculate total cost
double calculateTotalPrice(arrayPtr cost, arrayPtr cups,int arraySize)
{
    // Calculate the cost
    double sum = 0;
    for(int i = 0; i < arraySize; i++)
    {
        sum += (cost[i] * cups[i]);
    }

    // Return the sum
    return sum;
}