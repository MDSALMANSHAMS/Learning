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
    int arr[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(arr) / 4;

    reverse(arr, 1, 3);

    cout << "vect: ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << "  ";
    }
}