#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isIsomorphic(string s, string t)
{
    vector<int> indexS(200, 0); // Stores index of characters in string s
    vector<int> indexT(200, 0); // Stores index of characters in string t

    int len = s.length(); // Get the length of both strings

    if (len != t.length())
    { // If the lengths of the two strings are different, they can't be isomorphic
        return false;
    }

    for (int i = 0; i < len; i++)
    { // Iterate through each character of the strings
        // cout << indexS[h] << endl;
        if (indexS[s[i]] != indexT[t[i]])
        {                 // Check if the index of the current character in string s is different from the index of the corresponding character in string t
            return false; // If different, strings are not isomorphic
        }

        indexS[s[i]] = i + 1; // updating position of current character
        indexT[t[i]] = i + 1;
    }

    return true; // If the loop completes without returning false, strings are isomorphic
}

int main()
{
    string str1 = "add", str2 = "goo";

    bool res = isIsomorphic(str1, str2);
    // cout << res;
}
