// Given an array of integers, change the value of all odd indexed elements
// to multiple of 2 and increment all even indexed value by 10.

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {7, 22, 6, 88, 4};
    int size = sizeof(arr) / 4;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = arr[i] + 10;
        }

        else if (i % 2 != 0)
        {
            arr[i] = arr[i] * 2;
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}