/*
You have a set of integers s, which originally contains all the numbers from 1 to n.
Unfortunately, due to some error, one of the numbers in s got duplicated to another
number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the
error. Find the number that occurs twice and the number that is missing and return them
in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {0, 1, 2, 2, 4, 5, 5, 7, 8, 9};
    int len = nums.size();
    vector<int> correction = {};

    for (int i = 0; i < len; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            correction.push_back(nums[i]);
            correction.push_back(nums[i] + 1);
        }
    }

    int len_2 = correction.size();
    for (int i = 0; i < len_2; i++)
    {
        cout << correction[i] << " ";
    }
}