#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    // Introduce the program
    cout << "This program will calculate the area of a hexagon.\n";

    // Prompt user for a side of a hexagon
    double side;
    cout << "Please input the side of the hexagon: ";
    cin >> side;

    // Calculate the result
    double result = (6 * pow(side, 2)) / (4 * tan((M_PI / 6)));
    cout << "The area of the hexagon is: " << result;
    return 0;
}
