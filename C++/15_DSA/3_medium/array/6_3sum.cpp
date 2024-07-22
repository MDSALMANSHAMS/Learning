/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such
that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. Notice that the
solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void threeSum(vector<int> &nums)
{
    int len = nums.size();
    for (int i = 0; i < len - 2; i++)
    {
        for (int j = i + 1; j < len - 1; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                }
            }
        }
    }
    return;
}

int main()
{
    vector<int> nums = {0, 0, 0};
    threeSum(nums);

    return 0;
}