/*
You are given an integer array nums and two integers indexDiff and valueDiff. Find a
pair of indices (i, j) such that: i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.

Example 1:
Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0

Example 2:
Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
Output: false
Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three
conditions, so we return false.
*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> find_dup(const vector<int> &nums, int len)
{
    int a = -1, b = -1;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (nums[i] == nums[j])
            {
                a = i;
                b = j;
                return make_pair(a, b); // Return the pair directly
            }
        }
    }
    return make_pair(a, b); // If no duplicates, return (-1, -1)
}

int main()
{
    vector<int> nums = {1, 5, 9, 1, 5, 9};
    int indexDiff = 2, valueDiff = 3;
    int len = nums.size();
    bool result = false;

    pair<int, int> indices = find_dup(nums, len);
    int i = indices.first;
    int j = indices.second;

    // cout << i << " " << j << endl;

    // condition
    if (i != j && abs(i - j) <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff)
    {
        result = true;
    }
    // i != j ? result = true : result = false;
    // abs(i - j) <= indexDiff ? result = true : result = false;
    // abs(nums[i] - nums[j]) <= valueDiff ? result = true : result = false;

    cout << result;

    return 0;
}