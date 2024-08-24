/*
Given a string n representing an integer, return the closest integer (not including itself),
which is a palindrome. If there is a tie, return the smaller one. The closest is defined as the
absolute difference minimized between two integers.

Example 1:
Input: n = "123"
Output: "121"

Example 2:
Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
*/

#include <iostream>
#include <string>
using namespace std;

int checkPlendrmo(int num)
{
    int original = num;
    int reverse = 0;
    int digit = 0;

    while (original > 0)
    {
        digit = original % 10;
        reverse = reverse * 10 + digit;
        original = original / 10;
    }

    if (reverse == num)
        return num;

    else
        return 0;
}

int main()
{
    string s = "113875";
    int num = stoi(s);
    // cout << typeid(s).name() << endl;
    // cout << num[0] << endl;

    while (num >= 0)
    {
        if (num == 0)
        {
            cout << num << endl;
            break;
        }

        if (num / 10 == 0)
        {
            cout << num / 10 << endl;
            break;
        }

        int p = checkPlendrmo(num);

        if (p == 0)
            num--;

        else
        {
            cout << p << endl;
            break;
        }
    }
}

// O(num*d)
// d is number of digits in s