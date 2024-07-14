#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

// void reverse(int arr[], int i, int j)
// {
//     while (i < j)
//     {
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//         i++;
//         j--;
//     }
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6};
//     int length = sizeof(arr) / 4;

//     reverse(arr, 1, 3);

//     cout << "vect: ";
//     for (int i = 0; i < length; i++)
//     {
//         cout << arr[i] << "  ";
//     }
// }

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(nums) / 4;

    int i = 2, j = 5;
    while (i < j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }

    for (int k = 0; k < length; k++)
    {
        cout << nums[k] << " ";
    }
}