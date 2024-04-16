// Print n to 1

#include <iostream>
using namespace std;

int nto1(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * nto1(n - 1);
}

int main()
{
    cout << nto1(5);
}