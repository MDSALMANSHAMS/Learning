#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << "enter no.: ";
    cin >> i;

    if (i > 99 && i <= 999) // and operator
        cout << "three digit number";

    else
        cout << "not three digit number";
}