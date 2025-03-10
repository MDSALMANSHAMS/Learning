/*
You are given a 0-indexed array of unique strings words. A palindrome pair is a pair of integers
(i, j) such that: 0 <= i, j < words.length, i != j, and words[i] + words[j] (the concatenation
of the two strings) is a palindrome. Return an array of all the palindrome pairs of words. You
must write an algorithm with O(sum of words[i].length) runtime complexity.

Example 1:
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]

Example 2:
Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]

Example 3:
Input: words = ["a",""]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["a","a"]
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> words = {"bat", "tab", "cat"};

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (j == i)
                continue;

            for (int k = words[j].size() - 1; k > 0; k++)
            {
                char c = words[j][k];
                if (c == words[i][words[j].size() - k])
                    cout << c << " ";
            }
        }
    }
}