// WAP to check if a number is composite or not.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {

            cout << "composite number";
            break;
        }
        // cout << "prime number";
    }
}
