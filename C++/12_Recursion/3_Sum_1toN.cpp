// Print sum n to 1

#include <iostream>
using namespace std;

int sum = 0;

void nto1(int n)
{
    if (n == 0)
    {
        cout << "sum is: " << sum;
        return;
    }

    cout << n << endl;
    sum = sum + n;
    nto1(n - 1);
}

int main()
{
    nto1(10);
}