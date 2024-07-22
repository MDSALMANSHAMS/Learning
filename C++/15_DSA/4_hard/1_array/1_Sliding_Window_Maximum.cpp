/*
You are given an array of integers nums, there is a sliding window of size k which is
moving from the very left of the array to the very right. You can only see the k numbers
in the window. Each time the sliding window moves right by one position. Return the max
sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void slide_window_max(vector<int> &nums, int k, vector<int> &max_el)
{
    int len = nums.size();

    for (int i = 0; i <= len - k; i++)
    {
        int max_num = nums[i];
        for (int j = i + 1; j < i + k; j++)
        {
            if (nums[j] > max_num)
                max_num = nums[j];
        }
        max_el.push_back(max_num);
    }

    return;
}

int main()
{
    vector<int> nums = {1};
    int k = 1;
    vector<int> max_el = {};

    slide_window_max(nums, k, max_el);
    int len = max_el.size();

    for (int i = 0; i < len; i++)
    {
        cout << max_el[i] << " ";
    }

    return 0;
}