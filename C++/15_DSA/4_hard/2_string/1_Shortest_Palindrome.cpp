/*
You are given a string s. You can convert s to a palindrome by adding characters in
front of it. Return the shortest palindrome you can find by performing this
transformation.

Example 1:
Input: s = "aacecaaa"
Output: "aaacecaaa"

Example 2:
Input: s = "abcd"
Output: "dcbabcd"
*/

#include <iostream>
#include <string>
using namespace std;

bool ifPalindrome(string str)
{
    string che = "";

    for (int i = str.size() - 1; i >= 0; i--)
    {
        che.push_back(str[i]);
    }

    return che == str ? true : false;
}

int main()
{
    string s = "abcd", check = "";

    for (int i = s.size() - 1; i >= 0; i--)
    {
        check.push_back(s[i]);
    }

    cout << s << endl;
    cout << check << endl;

    for (int i = 0; i < s.size(); i++)
    {
        if (!ifPalindrome(check))
        {
            check.push_back(s[i]);
            // cout << "palindrome" << endl;
        }

        else
            break;
    }

    cout << check;
}