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
    vector<vector<string>> ans(strs.size());
    string s1 = "", s2 = "";

    for (int i = 0; i < strs.size(); i++)
    {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        // cout << temp << " ";

        // ans.push_back(strs);

        for (int j = 0; j < ans.size(); j++)
        {
            // cout << j << " ";                // cout << j << " ";
            if (temp == ans[j][0])
            {
                ans[j].push_back(strs[i]);
                break;
            }

            else
            {
                ans[j].push_back(strs[i]);
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << i << " " << j << " " << ans[i][j] << " ";
        }
        // cout << endl;
    }
}