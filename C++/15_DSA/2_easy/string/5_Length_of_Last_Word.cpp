/*
Given a string s consisting of words and spaces, return the length of the last word in
the string. A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "   fly me   to   the moon  ";
    int count = 0;
    int max_count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            count++;

            if (count > max_count)
                max_count = count;
        }

        else
            count = 0;
    }
    cout << max_count;
}