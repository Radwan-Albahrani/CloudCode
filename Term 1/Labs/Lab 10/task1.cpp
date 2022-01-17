#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    // Define Variables
    const int ROWS = 4, COLUMNS = 7;
    double weeks[ROWS][COLUMNS];
    double sum = 0, average = 0;
    double averages[4];

    // Prompt user for input
    cout << "Enter the rainfall rate for the four weeks: " << endl;
    for (int i = 0; i < ROWS; i++)
    {
        // Prepare input
        cout << "Week #" << i + 1 << ": ";
        for (int j = 0; j < COLUMNS; j++)
        {
            // Get input
            cin >> weeks[i][j];

            // Add it to sum
            sum += weeks[i][j];

            // Raise average by 1
            average++;
        }
        
        // Calculate average
        average = sum / average;

        // Add average to averages
        averages[i] = average;

        // Reset sum and average
        sum = 0;
        average = 0;
    }

    // Prepare output
    cout << "\n\nClassification for each week: \n";
  
    // Loop through averages
    for (int i = 0; i < ROWS; i++)
    {
        // Rate rainfall based on criteria
        string rating;
        if(averages[i] >= 6)
        {
            rating = "high";
        }
        else if (averages[i] < 6 && averages[i] > 3)
        {
            rating = "Medium";
        }
        else
        {
            rating = "Low";
        }

        // Display output
        cout << "Average Week#" << i + 1 << ": " << rating << " (" << averages[i]  << ")" << endl;
    }

    
    return 0;
}
