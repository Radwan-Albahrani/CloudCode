#include <iostream>
#include <cmath>
using namespace std;

int calDistance(double x1, double x2, double y1, double y2);
int main(int argc, char const *argv[])
{
    // Creating Variables
    srand(time(0));
    
    int xSara = rand();
    int ySara = rand();
    float distances[3];

    // Testing variable to find shortest distance
    int min = RAND_MAX;
    int longitude = 0;
    int latitude = 0;
    int number = 0;
    // Generate 3 random distances and add them to array
    for(int i = 0; i < 3; i++)
    {
        // Get random location
        int x = rand();
        int y = rand();
        
        // Get distance from sara
        int distance = calDistance(xSara, x, ySara, y);
        
        // Check if distance is minimum
        if(distance < min)
        {
            min = distance;
            longitude = x;
            latitude = y;
            int number = i;
        }

        // Add to array
        distances[i] = distance;
    }

    // Print results
    cout << fixed << "minimum Distance is: " << min << endl;
    cout << fixed << "Longitude: " << longitude << endl << "Latitude: " << latitude << endl;
    cout << endl << "Your location is: " << endl << "Longitude: " << xSara << endl << "Latitude: " << ySara << endl;

    

    return 0;
}


int calDistance(double x1, double x2, double y1, double y2)
{
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}
