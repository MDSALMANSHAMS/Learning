// Take positive integer input and tell if it is divisible by 5 and 3

#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << "enter no.: ";
    cin >> i;

    if (i == 0)
    {
        cout << "enter no above than zero: ";
        cin >> i;
    }

    if (i % 3 == 0 && i % 5 == 0) // and operator
    {
        cout << "divisible by 5 and 3" << endl;
        main();
    }

    else
    {
        cout << "not divisible by 5 and 3" << endl;
        main();
    }
}