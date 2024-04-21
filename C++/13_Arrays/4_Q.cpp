// calcuate the sum of all the element in the given array.

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {4, 7, -22, 8, 4, 888};
    int n = sizeof(arr) / 4;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    cout << sum;
}