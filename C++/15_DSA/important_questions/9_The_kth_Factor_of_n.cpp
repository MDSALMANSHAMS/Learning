/*
You are given two positive integers n and k. A factor of an integer n is defined as an integer i
where n % i == 0. Consider a list of all factors of n sorted in ascending order, return the kth
factor in this list or return -1 if n has less than k factors.

Example 1:
Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.

Example 2:
Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.

Example 3:
Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 7, k = 2;
    vector<int> factors = {};

    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
        }
    }
    factors.push_back(n);

    (factors[k - 1] > 0) ? cout << factors[k - 1] : cout << -1;
}