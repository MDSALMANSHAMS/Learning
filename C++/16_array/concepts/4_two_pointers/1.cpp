// Basic 0s and 1s sorting

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 1, 0, 1};
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            count++;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (i < count)
            nums[i] = 0;

        else
            nums[i] = 1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}