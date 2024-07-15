#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}

int main()
{
    int arr[] = {4, 2, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    int result = linearSearch(arr, n, target);

    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
