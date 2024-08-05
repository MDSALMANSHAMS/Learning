// two pointers

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 0, 1, 0, 1};

    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        if (nums[left] > nums[right])
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }

        else if (nums[left] == 0)
        {
            left++;
        }

        else if (nums[left] == 1)
        {
            right--;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}