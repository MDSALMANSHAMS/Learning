// Write a program to copy the contents of one array into another in the reverse order.

#include <iostream>
using namespace std;

int main()
{
    int arr_a[] = {7, 22, 6, 88, 4, -29, 5, 8, 33, 66};
    int size = sizeof(arr_a) / 4;
    int arr_b[size];

    for (int i = 0; i < size; i++)
    {
        int j = size - 1 - i;
        arr_b[i] = arr_a[j];
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr_b[i] << " ";
    }
}