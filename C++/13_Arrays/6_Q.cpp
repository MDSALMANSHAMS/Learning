// find the maximum value out of all the elements in the array.

#include <iostream>
using namespace std;

int main()
{
    int x = 19;
    int arr[x];

    for (int i = 0; i < x; i++)
    {
        arr[i] = (i + 1) * (i + 1);
    }

    for (int i = 0; i < x; i++)
    {
        cout << arr[i] << " ";
    }
}