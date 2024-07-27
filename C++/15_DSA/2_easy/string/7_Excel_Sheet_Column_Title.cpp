/*
Given an integer columnNumber, return its corresponding column title as it appears in
an Excel sheet.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num = 26;
    string str = "";

    if (num <= 26)
    {
        str.push_back(static_cast<char>(num + 64));
    }

    // str.push_back(as);

    cout << static_cast<char>(1 + 'A');
}