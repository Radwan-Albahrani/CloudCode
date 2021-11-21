#include <iostream>
#include <algorithm>
#include <array>

using namespace std;
int compare(const void *arg1, const void *arg2);
int main(int argc, const char** argv) 
{
    // Initialize array
    int a[5][2] =
    {
        {10,20},
        {30,5},
        {11,10},
        {9,19},
        {12,10}
    };

    // Sort array using values inside rows
    for (int i = 0; i < 5; i++)
    {
        sort(a[i], a[i] + 2);
    }
    
    qsort(a, 5, sizeof(*a), compare);
    cout << endl;
    // Output
    for (int i = 0; i < 5; i++)
    {
        
        for(int j = 0; j < 2; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;

    }
}

int compare(const void *arg1, const void *arg2)
{
    // Get first element
    int const *lhs = static_cast<int const*>(arg1);

    // Get second element
    int const *rhs = static_cast<int const*>(arg2);

    // Compare first element to second element as a 2D array
    // If both elements are equal, sort them with regards to the second element
    return (lhs[0] < rhs[0]) ? -1
        :  ((rhs[0] < lhs[0]) ? 1
        :  (lhs[1] < rhs[1] ? -1
        :  ((rhs[1] < lhs[1] ? 1 : 0))));
}