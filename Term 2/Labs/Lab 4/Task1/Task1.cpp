#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char const *argv[])
{
    // Present the program
    cout << "This program will find the distance between two points on the X Y plane.\n";

    // Prompt and get coordinates
    double x1, y1, x2, y2;
    cout << "Please enter X1 Y1 X2 Y2: ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Do the calculations
    double result = sqrt((pow(x2 - x1, 2)) + (pow(y2-y1, 2)));
    cout << "The distance between the two points is: " << result;

    return 0;
}
