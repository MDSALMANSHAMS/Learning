/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For
example, the array nums = [0,1,4,4,5,6,7] might become: [4,5,6,7,0,1,4] if it was rotated 4
times. [0,1,4,4,5,6,7] if it was rotated 7 times. Notice that rotating an array [a[0], a[1],
a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]]. Given
the sorted rotated array nums that may contain duplicates, return the minimum element of this
array. You must decrease the overall operation steps as much as possible.

Example 1:
Input: nums = [1,3,5]
Output: 1

Example 2:
Input: nums = [2,2,2,0,1]
Output: 0

binary search
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {2, 2, 2, 0, 1};
    int count = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            // cout << "here" << endl;
            count++;
        }

        else if (nums[i] == nums[i + 1])
        {
            for (i = i; i < nums.size(); i++)
            {
                if (nums[i] > nums[i + 1])
                {
                    count = count++;
                    break;
                }
            }
        }
    }

    if (nums[0] > nums[nums.size() - 1])
        count++;

    cout << count << endl;
}