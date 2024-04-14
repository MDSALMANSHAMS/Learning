// Find the sum from 1 to n

#include <iostream>
using namespace std;
int main()
{
    int n = 100;
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    cout << sum;
}
