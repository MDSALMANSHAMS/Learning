#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> str = {"antia", "anti", "antihem"};
    int len = str.size();
    sort(str.begin(), str.end());

    string s1 = str[0];
    string s2 = str[len - 1];

    string ans = "";

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == s2[i])
        {
            ans.push_back(s1[i]);
        }
        else
            break;
    }

    cout << ans;
}