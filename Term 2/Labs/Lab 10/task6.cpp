#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Initiating dynamic variables and giving the values
    int* firstnum = new int;
    *firstnum = 10;
    int* secondnum = new int;
    *secondnum = 20;

    // Printing Values before swap
    cout << "First Number before swap: " << *firstnum << endl;
    cout << "Second number before swap: " << *secondnum << endl;


    // Swapping
    int *temp;
    temp = firstnum;
    firstnum = secondnum;
    secondnum = temp;


    // Printing Values After swap
    cout << "First Number after swap: " << *firstnum << endl;
    cout << "Second Number After swap: " << *secondnum << endl;
    return 0;
}
