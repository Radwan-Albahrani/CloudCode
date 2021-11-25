#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[])
{
    // Initialize array
    char string[50];

    // Get string from user
    cout << "Enter a string: ";
    cin.getline(string, 50);

    // Convert uppercase to lowercase and vice versa
    for (int i = 0; i < strlen(string); i++)
    {
        if (isupper(string[i]) != 0)
        {
            string[i] = tolower(string[i]);
        }
        else
        {
            string[i] = toupper(string[i]);
        }
    }

    cout << string << endl;
    return 0;
}
