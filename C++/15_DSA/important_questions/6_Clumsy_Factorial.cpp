/*
Example 1:
Input: n = 4
Output: 7
Explanation: 7 = 4 * 3 / 2 + 1

Example 2:
Input: n = 10
Output: 12
Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
*/

#include <iostream>
using namespace std;

int main()
{
    int n = 6;
    int ans = n;

    for (int i = n - 1; i > 0; i--)
    {
        if (true)
        {
            ans = ans * i;
        }
    }
}