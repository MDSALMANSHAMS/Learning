/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown
pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k],
nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example,
[0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2]. Given
the array nums after the possible rotation and an integer target, return the index of
target if it is in nums, or -1 if it is not in nums.
Note: You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
*/

#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &nums, int initial, int final)
{
    while (initial < final)
    {
        int temp = nums[initial];
        nums[initial] = nums[final];
        nums[final] = temp;
        initial++;
        final--;
    }
}

int check(vector<int> &nums, int target, int len)
{
    int initial = 0, final = len - 1, mid;
    while (initial <= final)
    {
        mid = initial + (final - initial) / 2;
        // cout << initial << endl;
        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            initial = mid + 1;
        else
            final = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int len = nums.size();
    int k = 3;
    int target = 7;

    reverse(nums, 0, len - k - 1);
    reverse(nums, len - k, len - 1);
    reverse(nums, 0, len - 1);

    int result = check(nums, target, len);
    cout << result;

    return 0;
}
