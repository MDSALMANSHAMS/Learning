/*
You are given two integer arrays nums1 and nums2 of length n. The XOR sum of the two
integer arrays is (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1]
XOR nums2[n - 1]) (0-indexed). For example, the XOR sum of [1,2,3] and [3,2,1] is equal
to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4. Rearrange the elements of nums2
such that the resulting XOR sum is minimized. Return the XOR sum after the rearrangement.

Example 1:
Input: nums1 = [1,2], nums2 = [2,3]
Output: 2
Explanation: Rearrange nums2 so that it becomes [3,2].
The XOR sum is (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2.

Example 2:
Input: nums1 = [1,0,3], nums2 = [5,3,4]
Output: 8
Explanation: Rearrange nums2 so that it becomes [5,4,3].
The XOR sum is (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8.
*/

#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

int xor_arr(vector<int> &nums1, vector<int> &nums2, int len)
{
    int result = 0;

    for (int i = 0; i < len; i++)
    {
        int max_num = 0;
        int min_num = 0;

        max_num = max(nums1[i], nums2[i]);
        min_num = min(nums1[i], nums2[i]);

        result = result + (max_num - min_num);
    }

    return result;
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {2, 3};
    int len = nums1.size();
    sort(nums2.begin(), nums2.end(), greater<int>());

    int result = xor_arr(nums1, nums2, len);
    cout << result;

    return 0;
}
