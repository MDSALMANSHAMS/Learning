/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
The order of the elements may be changed. Then return the number of elements in nums which are
not equal to val.

Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
*/

#include <iostream>
using namespace std;

// // 1
// int my_fun(int nums[], int length, int val)
// {
//     int k = 0;

//     for (int i; i < length; i++)
//     {
//         if (nums[i] == val)
//             continue;

//         else
//             k++;
//     }

//     cout << "no. of element: " << k << endl;
//     return 0;
// }

// int main()
// {
//     int nums[] = {3, 2, 2, 3};
//     int val = 3;
//     int length = sizeof(nums) / 4;

//     my_fun(nums, length, val);
//     return 0;
// }

// 2
int main()
{
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int length = sizeof(nums) / 4;
    int val = 2;

    int index = 0;
    int k = 0;

    for (int i = 0; i < length; i++)
    {
        if (nums[i] != val)
        {
            nums[index] = nums[i];
            index++;
            k++;
        }
    }

    cout << "k is: " << k << endl;

    cout << "Modified array: [ ";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "]";
}
