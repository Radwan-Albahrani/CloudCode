#include <iostream>

using namespace std;

void updateValue1(int & x, int * y);
void updateValue2(int *x, int &y);

int main(int argc, char const *argv[])
{
    // Initiating Variables
    int x = 100;
    int y = 360;

    // Using functions to update values
    updateValue1(x, &y);
    updateValue2(&x, y);

    // Outputing values
    cout << "Outside Functions: \nX = " << x << endl << "Y = " << y;
    return 0;
}

void updateValue1(int & x, int * y)
{
    // Updating Value and printing
    x -= 10;
    cout << "Inside UpdateValue1, x = " << x << endl;

    // Updating value and printing
    *y += 50;
    cout << "Inside UpdateValue1, y = " << *y << endl;

}

void updateValue2(int *x, int &y)
{
    // Updating value and printing
    *x *= 2;
    cout << "Inside UpdateValue2, x = " << *x << endl;

    // Updating Value and printing
    y /= 10;
    cout << "Inside UpdateValue2, y = " << y << endl;
}