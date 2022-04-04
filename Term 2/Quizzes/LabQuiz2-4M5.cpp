/*
Write a C++ program to add, subtract, mulitply and 
divide two fractions and display the result fraction. 
Your program will prompt the user to input fraction 1 and fraction 2. 
Each fraction is in the form of two numbers: numerator and denominator of each fraction.
*/

#include <iostream>
#include <string>
using namespace std;

struct Fract 
{   int num; 
    int deno; 
}; 
Fract add(Fract,Fract); 
Fract sub(Fract,Fract);
Fract mul(Fract,Fract);
Fract div(Fract,Fract);

int main(int argc, char const *argv[])
{
    // Create Variable
    Fract num1;
    Fract num2;
    
    // Get the fractions
    cout << "Enter Fraction 1 (Numerator Denominator): ";
    cin >> num1.num >> num1.deno;

    cout << "Enter Fraction 2 (Numerator Denominator): ";
    cin >> num2.num >> num2.deno;

    // Choose operation
    char choice;
    cout << "Choose Operation ( Plus: +, Minus: - , Multiply: *, Divide: /): ";
    cin >> choice;
    Fract result;
    if(choice == '+')
    {
        result = add(num1, num2);
    }
    else if(choice == '-')
    {
        result = sub(num1, num2);
    }
    else if(choice == '*')
    {
        result = mul(num1, num2);
    }
    else if(choice == '/')
    {
        result = div(num1, num2);
    }
    else
    {
        cout << "Choice not Valid\n";
        return -1;
    }

    // Print out the result
    cout << "Resultant Fraction = :" << result.num << "/" << result.deno << endl;
    return 0;
}

// Add
Fract add(Fract num1, Fract num2)
{
    // Initiaite Result
    Fract result;

    // Combine Denominators
    result.deno = (num1.deno * num2.deno);

    // Multiply numerators by opposite denominators and add
    result.num = (num1.num * num2.deno) + (num2.num * num1.deno);

    // Find Simplest Form
    for(int i = 2; i < 9; i++)
    {
        if(result.num % i == 0 && result.deno % i == 0)
        {
            result.num = result.num/i;
            result.deno = result.deno/i;
        }
    }
    return result;
}

Fract sub(Fract num1, Fract num2)
{
    Fract result;

    // Find a common denominator
    result.deno = (num1.deno * num2.deno);

    // Multiply Each numerator by the opposite denominator and subtract
    result.num = (num1.num * num2.deno) - (num2.num * num1.deno);

    // Find Simplest Form
    for(int i = 2; i < 9; i++)
    {
        if(result.num % i == 0 && result.deno % i == 0)
        {
            result.num = result.num/i;
            result.deno = result.deno/i;
        }
    }

    // Return result
    return result;
}

// Multiply
Fract mul(Fract num1,Fract num2)
{
    // Initiate result
    Fract result;

    // Multiply numerator by numerator and denominator by denominator
    result.num = num1.num * num2.num;
    result.deno = num1.deno * num2.deno;
    
    // Find Simplest Form
    for(int i = 2; i < 9; i++)
    {
        if(result.num % i == 0 && result.deno % i == 0)
        {
            result.num = result.num/i;
            result.deno = result.deno/i;
        }
    }

    // Return result
    return result;
}

// Divide
Fract div(Fract num1, Fract num2)
{
    // Initiate result
    Fract result;

    // Multiply by reciprocal 
    result.num = num1.num * num2.deno;
    result.deno = num1.deno * num2.num;
    
    // Find Simplest Form
    for(int i = 2; i < 9; i++)
    {
        if(result.num % i == 0 && result.deno % i == 0)
        {
            result.num = result.num/i;
            result.deno = result.deno/i;
        }
    }

    // Return result
    return result;
}
