// find the maximum value out of all the elements in the array.

#include <iostream>
using namespace std;

int max_num(int arr[], int size)
{
    int max = arr[0]; // INT_MIN;

    for (int j = 0; j < size; j++)
    {
        if (arr[j] > max)
        {
            max = arr[j];
        }
    }

    return max;
}

int main()
{
    int arr[] = {4, 7, -22, 8, 999, 888};
    int size = sizeof(arr) / 4;

    cout << max_num(arr, size);
}