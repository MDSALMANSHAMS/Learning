/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

#include <iostream>
using namespace std;

int majorityElement(int nums[], int length)
{
    int x = 0;
    int count = 0;

    // Phase 1: Find a candidate for majority element
    for (int i = 0; i < length; i++)
    {
        if (count == 0)
            x = nums[i];

        if (nums[i] == x)
            count++;

        else
            count--;
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int i = 0; i < length; i++)
    {
        if (nums[i] == x)
            count++;
    }

    if (count > length / 2)
        return x;

    else
        return -1;
}

int main()
{
    int nums[] = {2, 2, 1, 1, 1, 2};
    int length = sizeof(nums) / 4;

    int majority = majorityElement(nums, length);
    cout << "The majority element is: " << majority << endl;

    return 0;
}