/*
You are given an array of strings words and a string pref. Return the number of strings in words
that contain pref as a prefix. A prefix of a string s is any leading contiguous substring of s.

Example 1:
Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

Example 2:
Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> words = {"pay", "attention", "practice", "aetnd"};
    string pref = "at";
    int count = 0;

    for (int i = 0; i < words.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < pref.size(); j++)
        {
            if (words[i][j] == pref[j])
                flag = true;

            else
                flag = false;
        }

        if (flag)
        {
            count++;
        }
    }

    cout << count;
}