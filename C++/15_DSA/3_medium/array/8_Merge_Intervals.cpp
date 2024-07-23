/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping
intervals, and return an array of the non-overlapping intervals that cover all the
intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<vector<int>> nums = {{1, 4}, {4, 5}}; // {1, 3}, {2, 6}, {8, 10}, {15, 18}
    int len = nums.size();
    int sub_len = nums[0].size();
    vector<vector<int>> ans = {};

    for (int i = 0; i < len - 1; i++)
    {
        if (ans.empty())
        {
            ans.push_back(nums[i]);
            // cout << ans[i][1];
        }

        if (nums[i][sub_len - 1] > nums[i + 1][0])
        {
            // cout << "hi " << ans[i][sub_len - 1] << " " << nums[i + 1][sub_len - 1];
            ans[i][sub_len - 1] = nums[i + 1][sub_len - 1];
            i++;
        }

        else
        {
            ans.push_back(nums[i]);
        }
    }

    ans.push_back(nums[len - 1]);

    int len_2 = ans.size();
    int sub_len_2 = ans[0].size();

    for (int i = 0; i < len_2; i++)
    {
        for (int j = 0; j < sub_len_2; j++)
        {
            cout << ans[i][j] << " ";
        }
    }

    return 0;
}