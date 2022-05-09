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
            // Start a data string
            string Data;

            // Extract index number from this data.
            for(int i = foundResult + 8, j = 0; i < foundResult + 5 + 7; i++, j++)
            {
                Data += line[i];
            }

            // Convert that number to an integer and store it in output data
            outputData << stoi(Data) << endl;

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

                // Loop from 0 to start index and add that to tags
                for(int j = 0; j < startindex + 1; j++)
                {
                    tag += line[j];
                }

                // Loop from start index to end index and add that to current data
                for(int j = startindex + 1; j < endIndex; j++)
                {
                    currentData += line[j];
                }

                // Put current data in output with a /t
                outputData << "\t" << currentData << endl;

                // Loop from endindex to end of line and add that to tags
                for(int j = endIndex; j < endofline + 1; j++)
                {
                    tag += line[j];
                }

                // write it in tags file
                tags << tag << endl;
            }
        }

        // If it doesnt have a testID, just add it as is to tags
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
        if(Test[0] != '\t')
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