#include <iostream>
using namespace std;
int main()
{
    int x = 101;
    string y = to_string(x);

    string z = {};
    for (int i = y.size() - 1; i >= 0; i--)
    {
        z = z + y[i];
    }
    int a = stoi(z);
    if (a == x)
    {
        cout << "palindrom";
    }
    else
    {
        cout << "not palindrom";
    };
}