#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[])
{
    // Initialize array
    string words;

    // Get words from user
    cout << "Enter a string: ";
    getline(cin, words);

    // Convert uppercase to lowercase and vice versa
    for (int i = 0; i < words.length(); i++)
    {
        if (isupper(words[i]) != 0)
        {
            words[i] = tolower(words[i]);
        }
        else
        {
            words[i] = toupper(words[i]);
        }
    }

    cout << words << endl;
    return 0;
}
