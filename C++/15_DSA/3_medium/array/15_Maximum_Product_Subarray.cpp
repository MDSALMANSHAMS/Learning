/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {-2, 0, -1};
    int product = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] * nums[i + 1] > product)
        {
            product = nums[i] * nums[i + 1];
        }
    }

    cout << product << endl;
}