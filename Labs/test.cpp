#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char** argv) 
{
    int testing[5];
    for (size_t i = 0; i < 5; i++)
    {
        testing[i] = i*2+1;
    }
    
    cout << *max_element(testing, testing + 5);
    return 0;
}