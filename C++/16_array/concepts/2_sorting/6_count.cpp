#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countSort(vector<int> &arr)
{
    // Find the maximum and minimum values in the array
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    // Create a count array to store the count of each unique element
    vector<int> count(range, 0);
    // Create an output array to store the sorted array
    vector<int> output(arr.size(), 0);

    // Store the count of each element in the count array
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i] - min_val]++;
    }

    // Change count[i] so that count[i] now contains the actual position of this element in the output array
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
