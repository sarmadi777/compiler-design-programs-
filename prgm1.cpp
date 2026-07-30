#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str;
    cout << "Enter expression: ";
    getline(cin, str);

    int tokens = 0;

    for (int i = 0; i < str.length(); i++) {

        // Identifier, keyword, or number
        if (isalnum(str[i])) {
            while (i < str.length() && isalnum(str[i]))
                i++;
            tokens++;
            i--;
        }

        // Operators and special symbols
        else if (!isspace(str[i])) {
            tokens++;
        }
    }

    cout << "Total Tokens = " << tokens;

    return 0;
}