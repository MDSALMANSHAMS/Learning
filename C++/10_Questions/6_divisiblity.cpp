// Take positive integer inputs and tell if it is divisible by
// 5 or 3 but not by 15.

#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << "enter no. " << endl;
    cin >> i;

    if ((i % 5 == 0 || i % 3 == 0) && (i % 15 != 0))
        cout << "result" << endl;

    else
        cout << "not result" << endl;
}