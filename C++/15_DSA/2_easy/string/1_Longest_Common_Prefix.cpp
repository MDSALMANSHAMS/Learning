/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include <iostream>
using namespace std;

int main()
{
    string strs[] = {"flower", "flow", "flight"};
    int length = sizeof(strs) / sizeof(strs[0]);

    if (length == 0)
        return 0;

    string pref = strs[0];
    int prefLen = pref.length();
    // cout << pref << " " << prefLen << endl;

    for (int i = 1; i < length; i++)
    {
        string s = strs[i];
        // cout << i << " " << s << endl;
        // cout << i << " " << prefLen << " " << s.length() << endl;
        // cout << s.substr(0, prefLen) << endl;

        while (prefLen > s.length() || pref != s.substr(0, prefLen))
        {
            // cout << i << endl;
            prefLen--;
            if (prefLen == 0)
            {
                return 0;
            }
            pref = pref.substr(0, prefLen);
        }
    }
    cout << pref;
    return 1;
}