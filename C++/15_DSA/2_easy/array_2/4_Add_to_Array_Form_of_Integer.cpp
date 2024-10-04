/*
The array-form of an integer num is an array representing its digits in left to right order.
For example, for num = 1321, the array form is [1,3,2,1]. Given num, the array-form of an
integer, and an integer k, return the array-form of the integer num + k.

Example 1:
Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:
Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

Example 3:
Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> num = {1, 2, 0, 0}, ans;
    int k = 34;
    int n;

    for (int i = 0; i < num.size(); i++)
    {
        n = n + num[i];
        n = n * 10;
        // cout << n << " ";
    }
    n = n / 10;
    // cout << n;

    n = n + k;
    cout << n << endl;

    // cout << sizeof(n);
    for (int i = 0; i < sizeof(n); i++)
    {
        int back = n / (10 * (sizeof(n) - i));
        cout << back << " ";
        // n = n / 10;
        //  ans.push_back(back);
    }
}