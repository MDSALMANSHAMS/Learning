/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous)
subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
*/

/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    vector<vector<int>> result(4);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            result[i].push_back(arr[j]);
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << i << " " << result[i][j] << endl;
        }
    }
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumOfSubarrayMinimums(vector<int> &arr)
{
    int n = arr.size();
    long long sum = 0;

    // Iterate over each starting index of subarrays
    for (int i = 0; i < n; i++)
    {
        int minElement = arr[i]; // Initialize the minimum element for the current subarray
        //  Iterate over each ending index of subarrays starting from i
        for (int j = i; j < n; j++)
        {
            // Update the minimum element in the current subarray
            // cout << i << " " << j << " " << minElement << " " << arr[j] << endl;
            minElement = min(minElement, arr[j]);
            // Add the minimum element of this subarray to the sum
            sum = sum + minElement;
            cout << sum << " ";
        }
    }

    return sum;
}

int main()
{
    vector<int> arr1 = {3, 1, 2, 4};
    int res = sumOfSubarrayMinimums(arr1);
    // cout << "Output: " << res << endl; // Expected Output: 17

    vector<int> arr2 = {11, 81, 94, 43, 3};
    // cout << "Output: " << sumOfSubarrayMinimums(arr2) << endl; // Expected Output: 444

    return 0;
}
