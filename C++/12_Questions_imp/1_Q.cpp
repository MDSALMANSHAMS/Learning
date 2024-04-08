// WAP to count the digits of a given number

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int count = 0;
    while (n > 0)
    {
        count++;
        n = n / 10;
    }
    cout << "The number of digits is " << count;
    return 0;
}