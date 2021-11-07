#include <iostream>

using namespace std;

int main(int argc, const char** argv) 
{
    int testing[5];
    for (size_t i = 0; i < 5; i++)
    {
        testing[i] = i*2+1;
    }
    
    cout << testing[4];
    return 0;
}