/*
You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value
and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000
*/

#include <iostream>
using namespace std;
int main()
{
    int nums[] = {5, 0, 10};
    int length = sizeof(nums) / 4;
    int k = 1;
    float max_sum = 0;
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < i + k; j++)
        {
            if (k + i <= length)
            {
                sum = sum + nums[j];
                // cout << "i: " << i << " j: " << j << " " << sum << endl;
            }
        }
        if (sum >= max_sum)
        {
            max_sum = sum;
            sum = 0;
        }
        else
            sum = 0;
    }

    float max_avg = max_sum / k;
    cout << max_avg << endl;

    return 0;
}