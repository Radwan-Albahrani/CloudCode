#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int check(string name);
int main(int argc, char const *argv[])
{
    // Variables
    string name;

    // Ask user for word
    cout << "Enter a word: ";
    cin >> name;
    int result = check(name);

    if(result == 1)
    {
        cout << "Word is a Palindrom!" << endl;
    }
    else
    {
        cout << "Word is NOT a palindrom" << endl;
    }
    return 0;
}

int check(string name)
{
    // Loop with multiple variables until i is bigger than j
    for (int i = 0, j = name.length() - 1; i < j; i++, j--)
    {
        // Compare first to last. if equal, continue
        if(tolower(name[i]) == tolower(name[j]))
        {
            continue;
        }
        // If at any point it was unequal, return 0
        else
        {
            return 0;
        }
    }

    // If loop was successful, return 1
    return 1;
}
