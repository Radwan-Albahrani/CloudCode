/*Write a C++ program that reads a file from the disk named “Alphanumeric.txt” 
containing various types of characters like alphabets, digits, punctuation 
symbols etc. and splits its contents and write them into the following files:
--All the alphabets (a-z |A-Z) must be stored in a file named “Alphabet.txt”
--All the digits/numbers (0-9) must be stored in a file named “Number.txt”
--All the remaining symbols must be stored in a file named “Other.txt”
Then display the files with appropriate labels.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

using namespace std;

int main(int argc, char const *argv[])
{
    // Start reading given file
    cout << "Reading file: " << endl;
    ifstream file;
    file.open("Alphanumeric.txt");

    // If the file is not open, tell user it doesn't exist. End program
    if(!file.is_open())
    {
        cout << "Error: File not found in current directory" << endl;
        return -1;
    }

    // If file exists, Start generating output
    cout << "Generating output: " << endl;
    fs::create_directory("Output") ? cout << "Directory Created. Output will be stored in Directory" << endl : cout << "Directory already exists, Output will be stored in Directory" << endl;

    // Create three text files and add them to output directory
    fstream alpha, numeric, other;
    alpha.open("Output/Alphabet.txt", ios_base::out);
    numeric.open("Output/Number.txt", ios_base::out);
    other.open("Output/Other.txt", ios_base::out);

    // Start a line variable
    string line;

    // Go through all file lines
    while(getline(file, line))
    {
        // Go through each character in each line and assign it to proper file
        for(int i = 0; i < line.length(); i++)
        {
            if(isalpha(line[i]) != 0)
            {
                alpha << line[i];
            }
            else if(isdigit(line[i]) != 0)
            {
                numeric << line[i];
            }
            else if (isalpha(line[i]) == 0 && isdigit(line[i]) == 0 && isspace(line[i]) == 0)
            {
                other << line[i];
            }
        }
    }

    // Close all files
    alpha.close();
    numeric.close();
    other.close();
    file.close();

    cout << "Output Generated Successfully" << endl;

    // Opening files as input
    alpha.open("Output/Alphabet.txt", ios_base::in);
    numeric.open("Output/Number.txt", ios_base::in);
    other.open("Output/Other.txt", ios_base::in);

    // Displaying letters
    cout << "Letters: ";
    bool letters = false, numbers = false, others = false;
    while(getline(alpha, line))
    {
        cout << line;
        letters = true;
    }
    cout << endl;
    
    // If no letters found, tell user
    if(!letters)
    {
        cout << "No Letters found" << endl;
    }

    // Displaying Numbers
    cout << "Numbers: ";
    while (getline(numeric, line))
    {
        cout << line;
        numbers = true;
    }
    cout << endl;

    // If no numbers found, Tell user
    if(!numbers)
    {
        cout << "No Numbers found" << endl;
    }

    // Displaying other symbols
    cout << "Others: ";
    while (getline(other, line))
    {
        cout << line;
        others = true;
    }
    cout << endl;

    //If no other found, Tell user.
    if(!others)
    {
        cout << "No Symbols found" << endl;
    }
    
    return 0;
}
