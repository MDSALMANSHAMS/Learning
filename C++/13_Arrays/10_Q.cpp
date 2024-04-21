// Find the second largest element in the given array

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {7, 22, 6, 88, 4, 29, 5, 8, 33, 66};
    int size = sizeof(arr) / 4;
    int temp;

    // Bubble shorting
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << arr[size - 2] << endl; // answer

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}