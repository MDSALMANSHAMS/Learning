#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> nums = {1, 2, 3, 3, 4, 5};

    // Remove consecutive duplicate elements
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    // Print the modified vector
    std::cout << "Modified vector:";
    for (int num : nums)
    {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
