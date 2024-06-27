/*
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order. You must write an algorithm with
O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
*/

#include <iostream>
using namespace std;

int main()
{
    int nums[] = {1, 3, 5, 6};
    int target = 0;
    int length = sizeof(nums) / 4;

    for (int i = 0; i < length; i++)
    {
        if (nums[i] == target)
        {
            cout << i << endl;
            break;
        }

        else if (target > nums[i] && target < nums[i + 1])
        {
            cout << i + 1 << endl;
            break;
        }
    }
}