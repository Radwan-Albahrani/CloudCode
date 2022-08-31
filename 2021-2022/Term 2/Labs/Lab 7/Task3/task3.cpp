// including
#include <iostream>
#include <string>
using namespace std;

// prototypes
double withdraw(double balance);
double deposit(double balance);
void view(string name, double balancebefore, double balance);

int main(int argc, char const *argv[])
{
    // Asking user for name
    string name;
    cout << "Please enter your name: ";
    cin >> name;

    // Preparing variables for loop
    char prompt = 0;
    double balance = 10000;
    double balanceNew;

    // Do while loop for menu
    do
    {
        // Asking the user to choose a task
        cout << "Please choose a task (to exit, type e):" << endl;
        cout << "d - Deposit" << endl;
        cout << "w - Withdraw" << endl;
        
        // Getting the user's Choice
        cout << "Enter your choice: ";
        cin >> prompt;

        // Doing actions based on choice;
        if(prompt == 'd')
        {
            // Getting new balance
            balanceNew = deposit(balance);

            // Displaying Balance
            cout << "\n\n";
            view(name, balance, balanceNew);

            // Setting old balance to new balance:
            balance = balanceNew;
        }

        else if (prompt == 'w')
        {
            // Getting new balance
            balanceNew = withdraw(balance);

            // Displaying balance
            cout << "\n\n";
            view(name, balance, balanceNew);

            // Setting old Balance to new balance
            balance = balanceNew;
        }
        
    } while (prompt != 'e');
    
    return 0;
}

// Withdraw function
double withdraw(double balance)
{
    // Setting withdraw amount
    double withdraw;
    cout << "Please Enter Withdraw amount: ";
    cin >> withdraw;

    // Returning new balance with checking if amount can be withdrawn
    if (withdraw > balance)
    {
        cout << "You do not have that amount of cash." << endl;
        return balance;
    }
    else
    {
        return balance - withdraw;
    }
}

// Deposit function
double deposit(double balance)
{
    // Setting Deposit amount
    double deposit;
    cout << "Please Enter Withdraw amount: ";
    cin >> deposit;

    // Returning new deposit
    return balance + deposit;
}

// View function
void view(string name, double balancebefore, double balance)
{
    // Display information
    cout << "Customer Name: " << name << endl;
    cout << "Old Balance: $" << balancebefore << endl;
    cout << "New Balance: $" << balance << "\n\n";
}
