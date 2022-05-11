#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // Create new directory for output
    _mkdir("Output") ? cout << "Directory Already Exists.\n" << endl : cout << "Created directory\n" << endl;
    
    // Get size of array
    string name;
    cout << "Enter your name: ";

    getline(cin, name);
    
    // Open new output file
    ofstream output;
    output.open("Output/Q2.txt");

    // Loop through name and add it but add underscore instead of space
    for(int i = 0; i < name.length(); i++)
    {
        if(name[i] == ' ')
        {
            output << "_";
        }
        else
        {
            output << name[i];
        }
    }
    // Close file
    output.close();

    // Open it as input
    ifstream input;
    input.open("Output/Q2.txt");

    // Start array of characters for password
    char password[name.length()/3];

    // Get the name from the file
    string line;
    getline(input, line);

    // Create password
    for(int i = 0; i < line.length(); i++)
    {
        // Start with required spot
        int spot = i * 3;
        
        // Check if spot is within length
        if(spot < line.length())
        {
            password[i] = line[spot];
        }
        // if not, break
        else
        {
            break;
        }
    }
    
    // Print password
    cout << "----------------------------------------------" << endl;
    cout << "Suggested Password: " << password << endl;
    return 0;
}
