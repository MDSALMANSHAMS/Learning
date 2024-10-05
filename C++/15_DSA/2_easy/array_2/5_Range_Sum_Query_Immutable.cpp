/*
Given an integer array nums, handle multiple queries of the following type: Calculate the sum
of the elements of nums between indices left and right inclusive where left <= right. Implement
the NumArray class: NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left
and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Example 1:

Input:
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]

Output:
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
*/

#include <iostream>
#include <vector>
using namespace std;

int sumRange(vector<int> &num, int left, int right)
{
    int sum;
    for (int i = left; i <= right; i++)
    {
        sum = sum + num[i];
    }
    return sum;
}

int numArray(vector<vector<int>> &left_right, int index)
{
    int left = left_right[index][0];
    int right = left_right[index][1];
    return left, right;
}

int main()
{
    vector<int> num = {-2, 0, 3, -5, 2, -1}, ans;
    vector<vector<int>> left_right = {{0, 2}, {2, 5}, {0, 5}};

    for (int i = 0; i < left_right.size(); i++)
    {
        int left, right = numArray(left_right, i);
        int sum = sumRange(num, left, right);
        // cout << sum << endl;
        ans.push_back(sum);
    }

    for (int n : ans)
    {
        cout << n << " ";
    }

    return 0;
}
