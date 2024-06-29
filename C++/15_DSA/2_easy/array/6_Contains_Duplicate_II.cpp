/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j
in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: false

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

/*
// not the efficient code
#include <iostream>
using namespace std;

int main()
{
    int nums[] = {5, 2, 3, 1, 2, 3};
    int length = sizeof(nums) / 4;
    int k = 1;

    int index_i;
    int index_j;

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (nums[i] == nums[j])
            {
                index_i = i;
                index_j = j;
                // cout << index_i << " " << index_j << endl;
                break;
            }
        }
        if (abs(index_i - index_j) <= k)
        {
            cout << "true";
            break;
        }
        if (abs(index_i - index_j) > k)
        {
            cout << "false";
            break;
        }
    }
    // cout << index_i << " " << index_j << endl;
}
*/

#include <iostream>
#include <cmath> // Include cmath for the abs() function
using namespace std;

int main()
{
    int nums[] = {5, 2, 3, 1, 2, 3};
    int length = sizeof(nums) / sizeof(nums[0]);
    int k = 4;

    bool condition = false;

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (nums[i] == nums[j] && abs(i - j) <= k)
            {
                cout << i << " " << j << endl;
                condition = true;
                break;
            }
        }
        if (condition)
        {
            break;
        }
    }

    cout << (condition ? "true" : "false") << endl;

    return 0;
}
