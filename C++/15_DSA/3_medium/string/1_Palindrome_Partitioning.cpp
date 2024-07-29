/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s = "aab";
    vector<char> ans = {};

    for (int i = 0; i < s.size(); i++)
    {
        // cout << s[i] << " ";
        ans.push_back(s[i]);
    }

    cout << ans[0];
}