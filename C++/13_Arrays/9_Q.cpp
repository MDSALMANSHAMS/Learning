// Find the difference between the sum of elements at
// even indices to the sum of elements at odd indices.

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {7, 22, 6, 88, 4, 29, 5, 33};
    int size = sizeof(arr) / 4;
    int sum_even = 0;
    int sum_odd = 0;

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            sum_even = sum_even + arr[i];
        }
        else
            sum_odd = sum_odd + arr[i];
    }

    cout << sum_even - sum_odd;
}