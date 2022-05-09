#include <iostream>
#include <fstream>
#include <direct.h>

using namespace std;
int getInt(string Prompt);
int main(int argc, char const *argv[])
{
    // Creating Output Directory
    _mkdir("Output") ? cout << "Directory Already Exists.\n" << endl : cout << "Created Output directory\n" << endl;

    // Start file objects
    ifstream inputData;
    ofstream tags;
    ofstream outputData;

    // Open Data file
    inputData.open("data.txt");

    // Open output files
    tags.open("Output/Tags.txt");
    outputData.open("Output/OutputData.txt");

    // If file is not opened, exit the program
    if(!inputData.is_open())
    {
        cout << "Make sure starting file is in the same diretory!\n";
        return -1;
    }

    // Start a string line
    string line;

    while(getline(inputData, line))
    {
        // Find if the current line has a TestID tag
        size_t foundResult = line.find("TestId");
        
        // If the line does have it
        if(foundResult != string::npos)
        {
            // Extract the necessary substring
            string Data = line.substr(foundResult + 8, foundResult + 8 + 4);
            
            // Convert that number to an integer and store it in output data
            outputData << stoi(Data) << endl;

            // Extract current tag
            string firstTag = line.substr(0, foundResult - 1);
            
            // Add Tag to Tags file
            tags << firstTag  << ">" << endl;



            // Loop for the next four lines
            for(int i = 0; i < 4; i++)
            {
                // Get the line
                getline(inputData, line);

                // Find end of first tag
                size_t startindex = line.find(">");

                // Find start of second tag
                size_t endIndex = line.find("<", startindex + 1);

                // Find end of line
                size_t endofline = line.find(">", endIndex + 1);

                // Prepare string for current data
                string currentData;

                // Prepare string for tag
                string tag;

                // Extract Tag
                tag += line.substr(0, startindex + 1);

                // Get data Substring
                currentData += line.substr(startindex + 1, endIndex - startindex - 1);

                // Put current data in output with a /t
                outputData << " " << currentData << endl;

                // Extract ending tag
                tag += line.substr(endIndex, endofline - endIndex + 1);

                // write it in tags file
                tags << tag << endl;
            }
        }

        // If it doesn't have a testID, just add it as is to tags
        else
        {
            tags << line << endl;
        }
    }

    // Close all files  
    inputData.close();
    tags.close();
    outputData.close();

    // Get choice from user
    int choice = getInt("Enter a Number: ");

    // Open output data
    inputData.open("Output/OutputData.txt");
    
    // start a test string
    string Test;

    // Loop through all data
    while(getline(inputData, Test))
    {
        // If the start of the Test string is not a tab
        if(Test[0] != ' ')
        {
            // Prepare a result integer
            int Result;

            // Try to convert that line into an integer
            try
            {
                Result = stoi(Test);
            }

            // If it cant be converted, continue
            catch(const std::exception& e)
            {
                continue;
            }

            // If that integer is the choice the user made
            if(choice == Result)
            {   
                // Print out the information
                for(int i = 0; i < 4; i++)
                {
                    getline(inputData, Test);
                    cout << Test << endl;
                }
                break;
            }
            
        }
    }
    return 0;
}



// Get Int from user
int getInt(string Prompt)
{
    // Initiate Variables
    string choice;
    int realChoice = 0;

    // Start a loop
    while(true)
    {
        // Try except to see if can get a number
        try
        {
            // Display Prompt
            cout << Prompt;

            // Get User input as string 
            getline(cin, choice);

            // Convert String to Integer
            realChoice = stoi(choice);

            // Exit loop
            break;
            
        }

        // Tell user it must be a number
        catch(const std::exception& e)
        {
            cout << "Input must be a number. Try again.\n";
            continue;
        }
    }
    
    // Return User input
    return realChoice;
}