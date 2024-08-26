/*
Given an integer n, return the number of trailing zeroes in n!. Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

Example 1:
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Example 3:
Input: n = 0
Output: 0
*/

#include <iostream>
#include <vector>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    int ans = n * fact(n - 1);

    return ans;
}

int main()
{
    int n = 3;
    int res = fact(n);

    (res % 10 == 0) ? cout << 0 : cout << 1;
}
