/*
Given a string "s" containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input
string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
*/

#include <iostream>
using namespace std;

int main()
{
    string s = "()[]{}";
    int length = s.length();

    bool condition = false;

    for (int i = 0; i < length; i++)
    {
        for (int j = 1; j < length; j++)
        {
            if (s[i] == '(' && s[j] == ')')
            {
                condition = true;
            }
            if (s[i] == '[' && s[j] == ']')
            {
                condition = true;
            }
            if (s[i] == '{' && s[j] == '}')
            {
                condition = true;
            }

            else
                condition = false;
        }
    }
    cout << condition;
}