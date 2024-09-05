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
#include <unordered_map>
using namespace std;

int main()
{
    vector<string> strs = {""};
    unordered_map<string, vector<string>> ans;

    string temp;
    for (int i = 0; i < strs.size(); i++)
    {
        temp = strs[i];
        sort(strs[i].begin(), strs[i].end());
        ans[strs[i]].push_back(temp);
    }

    // Print the unordered_map
    for (const auto &pair : ans)
    {
        cout << "[ ";
        for (const string &str : pair.second)
        {
            cout << str << " ";
        }
        cout << "]" << endl;
    }
}