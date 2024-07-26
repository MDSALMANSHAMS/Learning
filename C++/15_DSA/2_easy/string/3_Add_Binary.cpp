/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
    string a = "1010", b = "1011";
    int aInt = stoi(a, nullptr, 2); // The base 2 tells stoi to interpret "1101" as a binary number.
    int bInt = stoi(b, nullptr, 2);

    int ans = aInt + bInt;
    bitset<10> binary(ans);
    // string binaryString = binary.to_string();

    cout << binary << endl;
    return 0;
}
