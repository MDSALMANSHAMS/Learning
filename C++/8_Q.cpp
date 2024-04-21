// Count the no. of elements in given array greater than a given no. x

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {7, 22, 6, 88, 4, 29, 5, 33};
    int size = sizeof(arr) / 4;
    int x = 10;
    int num = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > x)
        {
            num += 1;
        }
    }

    cout << num;
}