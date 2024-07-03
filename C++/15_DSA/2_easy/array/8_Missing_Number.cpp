/*
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2].
2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {3, 0, 1};
    int length = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < length; i++)
    {
        // if(nums[i] != i)
        if (nums[i + 1] - nums[i] != 1)
        {
            cout << nums[i] + 1 << endl;
            break;
        }
    }
}
