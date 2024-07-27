/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase
letters and removing all non-alphanumeric characters, it reads the same forward and
backward. Alphanumeric characters include letters and numbers. Given a string s, return
true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

#include <iostream>
#include <string>
#include <cctype> // for std::tolower
using namespace std;

int main()
{
    string s = " ", dum = "", rev = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ' && s[i] != ',' && s[i] != ':')
        {
            dum.push_back(tolower(s[i]));
        }
    }
    // cout << dum.size() << endl;

    for (int i = dum.size() - 1; i >= 0; i--)
    {
        rev.push_back(dum[i]);
    }

    dum == rev ? cout << "true" : cout << "false";

    return 0;
}