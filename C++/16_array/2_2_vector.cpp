#include <iostream>
#include <vector>
#include <algorithm> // for std::find

int main()
{
    int nums[] = {1, 3, 5, 8};
    std::vector<int> nums2 = {3, 7};

    int length = sizeof(nums) / sizeof(nums[0]);
    int target = 3;

    // std::cout << nums << std::endl;
    // std::cout << nums + 1 << std::endl;
    // std::cout << nums + 2 << std::endl;
    // std::cout << nums + 3 << std::endl;
    // std::cout << nums + length << std::endl;

    // find(initial range, final range, target)
    // find(address of first element, address of last element, target)
    // find(0x61fe00, 0x61fe10, 2)

    // for array
    std::cout << std::find(nums, nums + length, target) << std::endl;

    // // for vector
    // std::cout << std::find(nums2.begin(), nums2.end(), target) << std::endl;

    std::cout << nums + length << std::endl;

    bool isNotInArray = (std::find(nums, nums + length, target) == nums + length);

    if (isNotInArray)
    {
        std::cout << target << " is not in the array." << std::endl;
    }
    else
    {
        std::cout << target << " is in the array." << std::endl;
    }

    return 0;
}
