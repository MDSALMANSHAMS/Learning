/*
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums1 = {4, 9, 5, 4};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    int len1 = nums1.size();
    int len2 = nums2.size();

    vector<int> nums_out = {};
    int len3 = 0;

    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            // important concept
            bool isNotInArray = (find(nums_out.begin(), nums_out.end(), nums1[i]) == nums_out.end());

            if (nums1[i] == nums2[j] && isNotInArray)
            {
                nums_out.push_back(nums1[i]);
                break;
            }
        }
    }
    len3 = nums_out.size();

    for (int k = 0; k < len3; k++)
    {
        cout << nums_out[k] << " ";
    }
}