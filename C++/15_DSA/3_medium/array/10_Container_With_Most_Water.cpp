/*
You are given an integer array height of length n. There are n vertical lines drawn such that
the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together
with the x-axis form a container, such that the container contains the most water. Return the
maximum amount of water a container can store. Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
*/

#include <iostream>
#include <vector>
using namespace std;

// int main()
// {
//     vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//     int maxArea = 0;

//     for (int i = 0; i < height.size() - 1; i++)
//     {
//         // del i * max(height[i], height[i + del i])
//         for (int j = i + 1; j < height.size(); j++)
//         {
//             if ((j - i) * min(height[i], height[j]) > maxArea)
//                 maxArea = (j - i) * min(height[i], height[j]);
//         }
//     }
//     cout << maxArea << endl;
// }

int main()
{
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int left = 0, right = nums.size() - 1, maxArea = 0;

    while (left < right)
    {
        maxArea = max(maxArea, (right - left) * min(nums[left], nums[right]));

        if (nums[left] < nums[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << "maxArea: " << maxArea << endl;
}
