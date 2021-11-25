#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // Define phone number and get it from user
    string phoneNumber;
    cout << "Enter you phone number (00 + area code + number): ";
    getline(cin, phoneNumber);

    // Create substring from the area code
    string areacode = phoneNumber.substr(0, 5);

    // Determine area code location
    if(areacode == "00966")
    {
        cout << "You are from Saudi Arabia." << endl;
    }
    else if(areacode == "00926")
    {
        cout << "You are from Jordan." << endl;
    }
    else if(areacode == "00971")
    {
        cout << "You are from United Arab Emarates." << endl;
    }
    else
    {
        cout << "Area not located/Number incorrect" << endl;
    }

    // End Program
    return 0;
}
