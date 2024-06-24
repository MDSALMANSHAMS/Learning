/*
Given an array of positive integers nums, return the maximum possible sum of an ascending subarray
in nums. A subarray is defined as a contiguous sequence of numbers in an array. A subarray
[numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1.
Note that a subarray of size 1 is ascending.

Example 1:
Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

Example 2:
Input: nums = [10,20,30,40,50]
Output: 150

Example 3:
Input: nums = [12,17,15,13,10,11,12]
Output: 33
*/

#include <iostream>
using namespace std;
int main()
{
    int nums[] = {10, 20, 30, 40, 50};
    int length = sizeof(nums) / 4;
    int sum = 0;
    int maxi = 0;

    for (int i = 0; i < length; i++)
    {
        sum += nums[i];
        // cout << i << " " << sum << endl;
        if (i < length - 1 && nums[i] >= nums[i + 1])
        {
            maxi = max(sum, maxi);
            // cout << i << " " << sum << " " << maxi << endl;
            sum = 0;
        }
    }
    cout << max(maxi, sum);
    return 0;
}