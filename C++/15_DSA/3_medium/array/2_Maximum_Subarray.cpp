/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/

#include <iostream>
#include <vector>
using namespace std;

int max_sum(vector<int> &nums, int len)
{
    int large_sum = 0;
    for (int i = 0; i < len; i++)
    {
        int current_sum = nums[i];
        for (int j = i + 1; j < len; j++)
        {
            current_sum = current_sum + nums[j];
            cout << "hi: " << current_sum << " " << large_sum << endl;
            large_sum = max(current_sum, large_sum);
            // cout << large_sum << endl;
        }
        // cout << i << " " << large_sum << endl;
        //   if (i == 1)
        //       break;
    }
    return large_sum;
}

int main()
{
    vector<int> nums = {1};
    int len = nums.size();

    int result = max_sum(nums, len);
    cout << result;

    return 0;
}