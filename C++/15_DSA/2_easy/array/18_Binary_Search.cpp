/*
Given an array of integers nums which is sorted in ascending order, and an integer target,
write a function to search target in nums. If target exists, then return its index. Otherwise,
return -1. You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

#include <iostream>
#include <vector>
using namespace std;

void binary_sea(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > target)
        {
            right = mid;
        }
        else if (nums[mid] < target)
        {
            left = mid;
        }

        else if (nums[mid] == target)
        {
            cout << mid << endl;
            break;
        }

        else
            cout << "-1";
    }
}

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 8;

    binary_sea(nums, target);

    return 0;
}
