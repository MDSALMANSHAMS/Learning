/*
Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include <iostream>
using namespace std;

int main()
{
    int nums[] = {1, 2, 3, 1};
    int length = sizeof(nums) / 4;
    bool result = false;

    for (int i = 0; i < length; i++)
    {
        // for (int j = i + 1; j < length; j++)
        // {
        //     if (nums[i] == nums[j])
        //         return true;
        // }
        for (int j = 0; j < length; j++)
        {
            if (nums[i] == nums[j] && i != j)
            {
                result = true;
            }
        }
    }

    cout << result << endl;
    return 0;
}