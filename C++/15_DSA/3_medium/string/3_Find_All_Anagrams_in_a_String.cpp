/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s.
You may return the answer in any order. An Anagram is a word or phrase formed by
rearranging the letters of a different word or phrase, typically using all the original
letters exactly once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s = "cbaebabacd", p = "abc", temp = "";
    vector<int> ans = {};

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < i + p.size(); j++)
        {
            temp.push_back(s[j]);
            if (j = i + p.size())

            {
                sort(temp.begin(), temp.end());
                if (temp == p)
                {
                    cout << i << endl;
                    ans.push_back(i);
                    temp = "";
                    break;
                }
            }
            // cout << temp << endl;
        }
    }
    cout << ans[0];
}