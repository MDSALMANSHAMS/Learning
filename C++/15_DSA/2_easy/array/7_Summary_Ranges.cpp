/*
You are given a sorted unique integer array nums. A range [a,b] is the set of all integers from a to b
(inclusive). Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such
that x is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:
"a->b" if a != b
"a" if a == b

Example 1:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
*/

#include <iostream>
using namespace std;

int main()
{
    int nums[] = {0, 1, 2, 4, 5, 7};
    int length = sizeof(nums) / sizeof(nums[0]);

    int start = nums[0];

    for (int i = 1; i < length; i++)
    {
        // If the current number is not consecutive
        if (nums[i] != nums[i - 1] + 1)
        {
            // Output the range
            if (start == nums[i - 1])
            {
                cout << start << endl; // Single number
            }
            else
            {
                cout << start << "->" << nums[i - 1] << endl; // Range
            }
            // Update the start of the new range
            start = nums[i];
        }
    }

    // Handle the last range
    if (start == nums[length - 1])
    {
        cout << start << endl;
    }
    else
    {
        cout << start << "->" << nums[length - 1] << endl;
    }

    return 0;
}
