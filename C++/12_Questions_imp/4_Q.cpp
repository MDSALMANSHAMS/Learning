// WAP to print the sum of given no. and its reverse.

#include <iostream>
using namespace std;
int main()
{
    int n = 123;
    int rev = 0;
    int sum = n;

    while (n > 0)
    {
        int digit = n % 10;
        n = n / 10;

        rev = (rev * 10) + digit;
    }

    sum = sum + rev;
    cout << sum;
}
