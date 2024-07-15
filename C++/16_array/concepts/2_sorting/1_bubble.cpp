#include <iostream>
using namespace std;

void bubbleSort(int arr[], int len)
{
    for (int j = 0; j < len - 1; j++)
    {
        for (int i = 0; i < len - j - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        // if (j == 1)
        //     break;
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, len);
    cout << "Sorted array: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}