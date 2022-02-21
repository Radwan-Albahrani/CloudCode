#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    // Introduce the program
    cout << "This program will convert a string to uppercase letters.\n";

    // Prompt the user for a name
    string name;
    cout << "Enter a name: ";
    cin >> name;

    // Loop through the name and uppercase any letters
    for(int i = 0; i < name.length(); i++)
    {
        name[i] = toupper(name[i]);
    }

    cout << "Welcome " << name;
    return 0;
}
