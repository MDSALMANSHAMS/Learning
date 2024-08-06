/*
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
You may assume the input array always has a valid answer.

Example 1:
Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

Example 2:
Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {1, 3, 2, 2, 3, 1};
    int ans[6] = {};
    sort(nums.begin(), nums.end());
    int j = 1;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        ans[j] = nums[i];
        j = j + 2;

        if (j >= nums.size())
        {
            j = 0;
        }
        // cout << nums[i] << " ";
    }

    for (int i = 0; i < 6; i++)
    {
        // cout << nums[i] << " ";
        cout << ans[i] << " ";
    }
}