/*
Given an unsorted integer array nums. Return the smallest positive integer that is not
present in nums. You must implement an algorithm that runs in O(n) time and uses O(1)
auxiliary space.

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int main()
// {
//     vector<int> nums = {1, 2, 0};
//     int len = nums.size();
//     sort(nums.begin(), nums.end());
//     vector<int> ans = {};

//     for (int i = 0; i < len; i++)
//     {
//         if (nums[i] > 0)
//         {
//             ans.push_back(nums[i]);
//         }
//         // cout << i << " ";
//     }

//     int len_2 = ans.size();
//     // cout << len_2 << " ";

//     for (int i = 0; i < len_2; i++)
//     {
//         if (ans[i] != i + 1)
//         {
//             cout << i + 1;
//             break;
//         }

//         else if (i == len_2 - 1)
//         {
//             cout << len_2 + 1;
//         }
//     }

//     return 0;
// }

int main()
{
    vector<int> nums = {7, 8, 9, 11, 12};
    int j = 1;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < j)
        {
            continue;
        }

        if (nums[i] == j)
        {
            j++;
        }
    }

    cout << j;
    return 0;
}
