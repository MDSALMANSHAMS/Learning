/*
Given an array of strings strs, group the anagrams together. You can return the answer
in any order. An Anagram is a word or phrase formed by rearranging the letters of a
different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> ans = {};
    string s1 = "", s2 = "";

    for (int i = 0; i < strs.size() - 1; i++)
    {
        for (int j = i + 1; j < strs.size(); j++)
        {
            // cout << i << " " << j << endl;
            s1 = strs[i];
            s2 = strs[j];
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());

            if (s1 == s2 && !s1.empty())
            {
                cout << strs[j] << endl;
                ans.push_back(strs[j]);
                s1 = "";
                s2 = "";
            }
            // cout << s1 << endl;
        }
    }

    // cout << ans.size();

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            // cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}