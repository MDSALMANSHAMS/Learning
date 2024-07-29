/*
Given an array of strings words, return the first palindromic string in the array.
If there is no such string, return an empty string "". A string is palindromic if it
reads the same forward and backward.

Example 1:
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.

Example 2:
Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".

Example 3:
Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrom(string s)
{
    string check = "";
    for (int i = s.size() - 1; i >= 0; i--)
        check.push_back(s[i]);

    return check == s ? true : false;
}

int main()
{
    vector<string> words = {"abc", "car", "ada", "racecar", "cooc"};

    for (int i = 0; i < words.size(); i++)
    {
        if (isPalindrom(words[i]))
            cout << words[i] << endl;
    }

    return 0;
}