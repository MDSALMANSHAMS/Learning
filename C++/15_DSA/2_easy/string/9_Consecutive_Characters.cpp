/*The power of the string is the maximum length of a non-empty substring that contains
only one unique character. Given a string s, return the power of s.

Example 1:
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

Example 2:
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "abbcccddddeeeeedcba";
    int curr_c = 1;
    int max_c = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i + 1])
        {
            curr_c++;
            if (curr_c > max_c)
                max_c = curr_c;
        }

        else
            curr_c = 1;
    }

    cout << max_c;
}