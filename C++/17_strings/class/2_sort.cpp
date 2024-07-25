#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str = "geeksforgeeks";
    int len = str.size();
    // bool res = str[0] > str[3];

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

    cout << str << endl;
}