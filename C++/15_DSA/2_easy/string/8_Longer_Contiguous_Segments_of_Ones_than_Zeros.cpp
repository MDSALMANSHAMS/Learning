/*
Given a binary string s, return true if the longest contiguous segment of 1's is
strictly longer than the longest contiguous segment of 0's in s, or return false
otherwise.

For example, in s = "110100010" the longest continuous segment of 1s has length 2, and
the longest continuous segment of 0s has length 3.

Note that if there are no 0's, then the longest continuous segment of 0's is considered to have a length 0. The same applies if there is no 1's.

Example 1:
Input: s = "1101"
Output: true
Explanation:
The longest contiguous segment of 1s has length 2: "1101"
The longest contiguous segment of 0s has length 1: "1101"
The segment of 1s is longer, so return true.

Example 2:
Input: s = "111000"
Output: false
Explanation:
The longest contiguous segment of 1s has length 3: "111000"
The longest contiguous segment of 0s has length 3: "111000"
The segment of 1s is not longer, so return false.

Example 3:
Input: s = "110100010"
Output: false
Explanation:
The longest contiguous segment of 1s has length 2: "110100010"
The longest contiguous segment of 0s has length 3: "110100010"
The segment of 1s is not longer, so return false.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "110100010";
    int max_ones = 0;
    int curr_ones = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            curr_ones++;
            if (curr_ones > max_ones)
                max_ones = curr_ones;
        }

        else
            curr_ones = 0;
    }

    int curr_ze = 0;
    int max_ze = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            curr_ze++;
            if (curr_ze > max_ze)
                max_ze = curr_ze;
        }

        else
            curr_ze = 0;
    }

    // cout << max_ones << " " << max_ze;

    max_ones > max_ze ? cout << "true" : cout << "false";
}