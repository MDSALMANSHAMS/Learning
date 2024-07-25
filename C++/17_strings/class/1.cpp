// Strings are use to store the sequence of charecters.
// This not a data type, like arrays or char, but these are objects of a class std:string in C++.
// Dynamic memory allocation.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str1 = "hello";
    string str2 = "by";

    cout << str1 << " " << str2 << " " << str2[1] << endl;

    // ASCII
    char ch = str1[0];
    cout << int(ch) << endl;

    // reverse
    reverse(str1.begin(), str1.end());
    cout << str1 << endl;

    // substr
    cout << str1.substr(0, 3) << endl;

    // +
    cout << str1 + str2 << endl;

    // push_back
    char cha = 'n';
    str1.push_back(cha);
    cout << str1 << endl;

    // size
    cout << str1.size() << endl;

    // int to str
    int i = 9;
    string str3 = to_string(i);
    cout << str3 << endl;

    // sort
}