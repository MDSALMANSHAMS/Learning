/*
Given an integer array nums, move all 0's to the end of it while maintaining the
relative order of the non-zero elements. Note that you must do this in-place without
making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<int> &nums, int a, int b)
{
    while (a < b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        a++;
        b--;
    }
}

int main()
{
    vector<int> nums = {0};
    int length = nums.size();
    // cout << length << endl;
    sort(nums.begin(), nums.end());

    int a = 0, b = length - 1;

    for (int i = 0; i < length; i++)
    {
        // (nums[i] == 0) ? a = i : break; // we cannot use the ternary operator "? :" to control statements like "break".
        if (nums[i] == 0)
        {
            a = i;
        }
        else
        {
            a = i;
            break;
        }
    }

    // cout << a << endl;

    reverse(nums, a, b);
    reverse(nums, 0, b);

    for (int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
}