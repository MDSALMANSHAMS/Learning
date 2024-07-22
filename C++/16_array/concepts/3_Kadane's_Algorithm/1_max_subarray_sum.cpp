#include <iostream>
#include <vector>
using namespace std;

int kadane(vector<int> &nums, int len)
{
    int max_sum = 0;
    int current_sum = 0;
    for (int i = 0; i < len; i++)
    {
        current_sum = current_sum + nums[i];

        if (current_sum > max_sum)
            max_sum = current_sum;

        if (current_sum < 0)
            current_sum = 0;
    }

    return max_sum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int len = nums.size();

    int result = kadane(nums, len);
    cout << result;

    return 0;
}