// Print the factorial of a given no.

#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    cout << fact;
}
