/*
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying
at most one element. We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i
(0-based) such that (0 <= i <= n - 2).

Example 1:
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:
Input: nums = [4,2,1]
Output: false
Explanation: You cannot get a non-decreasing array by modifying at most one element.
*/

#include <iostream>
using namespace std;

int main()
{
    int nums[] = {4, 2, 1};
    int length = sizeof(nums) / 4;
    int k = 0;

    for (int i = 1; i < length; i++)
    {
        if (nums[i] < nums[i - 1])
        {
            k++;
        }
    }

    k > 1 ? cout << false : cout << true;
    return 0;
}