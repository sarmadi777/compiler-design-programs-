#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to check keyword
int isKeyword(string s)
{
    string keywords[] = {"int", "float", "char", "for", "if", "while", "return","print","printf"};

    for(int i = 0; i < 7; i++)
    {
        if(s == keywords[i])
            return 1;
    }
    return 0;
}

int main()
{
    string str, word = "";
    int tokens = 0;

    cout << "Enter Expression: ";
    getline(cin, str);

    for(int i = 0; i < str.length(); i++)
    {
        // Check word or number
        if(isalnum(str[i]))
        {
            word = "";

            while(i < str.length() && isalnum(str[i]))
            {
                word = word + str[i];
                i++;
            }

            i--;

            if(isKeyword(word))
                cout << word << " --> Keyword" << endl;
            else if(isdigit(word[0]))
                cout << word << " --> Number" << endl;
            else
                cout << word << " --> Identifier" << endl;

            tokens++;
        }

        // Ignore spaces
        else if(isspace(str[i]))
        {
            continue;
        }

        // Operators
        else if(str[i]=='+' || str[i]=='-' || str[i]=='*' ||
                str[i]=='/' || str[i]=='=' || str[i]=='<' ||
                str[i]=='>')
        {
            cout << str[i] << " --> Operator" << endl;
            tokens++;
        }

        // Special Symbols
        else
        {
            cout << str[i] << " --> Special Symbol" << endl;
            tokens++;
        }
    }

    cout << "\nTotal Tokens = " << tokens << endl;

    return 0;
}