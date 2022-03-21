#include <iostream>
#include <ctime>

using namespace std;
int evaluate(int, int);
int main(int argc, char const *argv[])
{
    // Randomizing number
    srand(time(0));

    // Generate number between 1 and 50
    int randomNumber = rand() % 50;
    
    // Get number from user
    int user = 0;
    cout << "Guessing game started!" << endl;
    do
    {
        cout << "Guess: ";
        cin >> user;

    } while (evaluate(user, randomNumber) != 0);
    cout << "Random number GUESSED!" << endl;
    return 0;
}

int evaluate(int user, int randomNumber)
{
    if(randomNumber > user)
    {
        cout << "Random number is Greater!" << endl;
        return 1;
    }
    else if (randomNumber < user)
    {
        cout << "Random number is Lower!" << endl;
        return -1;
    }
    else
    {
        return 0;
    }
}