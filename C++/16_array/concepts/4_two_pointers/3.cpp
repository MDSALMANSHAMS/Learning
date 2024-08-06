#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {3, 4, 1, 2, 5};
    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        if (nums[left] > nums[right])
        {
            swap(nums[left], nums[right]);
            right--;
        }

        else
        {
            left++;
        }
    }

    for (int num : nums)
    {
        cout << num << " ";
    }
}