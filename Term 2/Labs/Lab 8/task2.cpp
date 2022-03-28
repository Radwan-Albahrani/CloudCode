// Including 
#include <iostream>

// Fraction struct
struct Fraction
{
    int num, den;
};


using namespace std;

void multiply(Fraction fraction[]);

int main(int argc, char const *argv[])
{
    // Variables
    Fraction fractions[2];

    // Get the first fraction
    cout << "Enter the first fraction (Numerator SPACE Denominator): ";
    cin >> fractions[0].num >> fractions[0].den;

    // Get the second fraction
    cout << "Enter the second fraction (Numerator SPACE Denominator): ";
    cin >> fractions[1].num >> fractions[1].den;

    // Call multiply function
    multiply(fractions);
    return 0;
}

void multiply(Fraction fraction[])
{
    // Funding resultant
    Fraction resultant;
    resultant.num = fraction[0].num * fraction[1].num;
    resultant.den = fraction[0].den * fraction[1].den;

    cout << "Resultant Fraction: " << resultant.num << "/" << resultant.den << endl;
}
