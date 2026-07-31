#include <iostream>
#include <string>
using namespace std;

int main()
{
    string code, line;

    cout << "Enter source code (Type END to stop):\n";

    while (getline(cin, line))
    {
        if (line == "END")
            break;
        code = code + line + "\n";
    }

    for (int i = 0; i < code.length(); i++)
    {
        // Single-line comment
        if (code[i] == '/' && code[i + 1] == '/')
        {
            while (code[i] != '\n')
                i++;
        }

        // Multi-line comment
        else if (code[i] == '/' && code[i + 1] == '*')
        {
            i = i + 2;

            while (!(code[i] == '*' && code[i + 1] == '/'))
                i++;

            i++; // Skip '/'
        }

        // Normal character
        else
        {
            cout << code[i];
        }
    }

    return 0;
}