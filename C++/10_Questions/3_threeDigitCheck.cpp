// Take positive integer input and tell if it is a three digit number or not.

#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << "enter no.: ";
    cin >> i;

    if (i > 99 && i <= 999)
        cout << "three digit number";

    else
        cout << "not three digit number";
}