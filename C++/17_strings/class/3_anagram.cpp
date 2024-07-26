#include <iostream>
#include <string>
#include <vector>
using namespace std;

string sort_str(string str, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (str[i] < str[j])
            {
                swap(str[i], str[j]);
            }
        }
    }

    return str;
}

int main()
{
    string str1 = "anagram", str2 = "nagaram";
    int len = str1.size();
    // bool res = str[0] > str[3];

    string res1 = sort_str(str1, len);
    string res2 = sort_str(str2, len);

    res1 == res2 ? cout << "yes" : cout << "no";
}