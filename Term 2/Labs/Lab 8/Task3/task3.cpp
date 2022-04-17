// Including
#include <iostream>

// Struct
struct advertising
{
    int AdNo;
    float AdPercent;
    float adEarning;
};

// Namespace
using namespace std;

// Main
int main(int argc, char const *argv[])
{
    // Delare advertising variable
    advertising ads;

    // Get input from the user for all required fields
    cout << "Enter the number of ads on your website: ";
    cin >> ads.AdNo;
    cout << "Enter the percentage of ads that gained clicks: ";
    cin >> ads.AdPercent;
    cout << "Enter the earnings for clicked ads: ";
    cin >> ads.adEarning;

    // Multiply all three and cout
    cout << "Your total earnings are: $" << ads.AdNo * (ads.AdPercent/100) * ads.adEarning << endl;
    return 0;
}
