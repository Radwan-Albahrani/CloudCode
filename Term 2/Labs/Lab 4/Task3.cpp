#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // Introduce the program
    cout << "This program will evaluate your password strength.\n";
    
    // Get a password from the user
    string password;
    cout << "Enter your Password: ";
    getline(cin, password);

    // Prepare password checkers
    bool lowercase = false;
    bool uppercase = false;
    // For this one, just a simple short if should suffice
    bool longerlength = password.length() > 8 ? true : false;
    bool digit = false;

    // Loop through string and check password conditions
    for(int i = 0; i < password.length(); i++)
    {
        // If it has a lowercase letter, make that condition true
        if(islower(password[i]) == 0)
        {
            lowercase = true;
        }
        
        // If it has an uppercase letter, make that condition true
        if(isupper(password[i]) == 0)
        {
            uppercase = true;
        }

        // If it has a digit, make that condition true
        if(isdigit(password[i]) != 0)
        {
            digit = true;
        }
        
    }

    // Print out password results
    if(lowercase && uppercase && longerlength && digit)
    {
        cout << "Strength of Password: Strong" << endl;
    }
    else if(lowercase && uppercase && password.length() > 6)
    {
        cout << "Strength of Password: Moderate" << endl;
    }
    else
    {
        cout << "Strength of password: Weak" << endl;
    }
    return 0;
}
