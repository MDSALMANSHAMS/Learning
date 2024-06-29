/*
Given a non-empty array of integers nums, every element appears twice except for one.
Find that single one.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/

#include <iostream>
using namespace std;

int main()
{
    int nums[] = {1};
    int length = sizeof(nums) / 4;
    int single_num = nums[0];

    for (int i = 1; i < length - 1; i++)
    {
        if (nums[i] == single_num)
        {
            single_num = nums[i + 1];
        }
    }

    cout << single_num;
}