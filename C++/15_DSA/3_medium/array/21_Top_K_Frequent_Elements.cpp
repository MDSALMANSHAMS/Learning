/*
Given an integer array nums and an integer k, return the k most frequent elements. You may
return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 4}, res;
    int k = 3;

    unordered_map<int, vector<int>> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        ans[nums[i]].push_back(nums[i]);
    }

    for (const auto &pair : ans)
    {
        if (pair.second.size() >= k)
        {
            res.push_back(pair.first);
        }

        // cout << "[ ";
        // for (const int &num : pair.second)
        // {
        //     cout << num << " ";
        // }
        // cout << "]" << endl;
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}