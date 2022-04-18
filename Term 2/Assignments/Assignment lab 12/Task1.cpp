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
    ofstream alpha, numeric, other;
    alpha.open("Output/Alphabet.txt");
    numeric.open("Output/Number.txt");
    other.open("Output/Other.txt");

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
            else
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
    return 0;
}
