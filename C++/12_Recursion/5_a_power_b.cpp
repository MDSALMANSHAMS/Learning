// Make a function which calculates "a" raised to the power "b" using recursion.

#include <iostream>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    return a * power(a, b - 1);
}

int main()
{
    cout << power(10, 0);
}