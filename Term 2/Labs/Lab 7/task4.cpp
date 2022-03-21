// Including
#include <iostream>

// Namespace
using namespace std;

void numberFunction(int i)
{ 
    cout << "The number is: " << i << endl;
    if(i < 10)
    {
        numberFunction(i + 1);
    }

}

int main()
{
    numberFunction(1);
    return 0;
}
