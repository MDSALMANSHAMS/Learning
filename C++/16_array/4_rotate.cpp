#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

void reverse(int arr[], int i, int j)
{
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / 4;
    int k = 7;
    int rem = k % length;
    cout << rem << endl;

    reverse(arr, 0, length - rem - 1);
    reverse(arr, length - rem, length - 1);
    reverse(arr, 0, length - 1);

    cout << "arr: ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << "  ";
    }
}