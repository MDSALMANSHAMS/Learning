// Take 3 positive integers input and print the greatest of them.

#include <iostream>
using namespace std;

int main()
{
    int i, j, k;
    cout << "enter numbers" << endl;
    cin >> i >> j >> k;

    if (i > j)
    {
        if (i > k)
            cout << "i: " << i << " is greatest" << endl;
        else
            cout << "k: " << k << " is greatest" << endl;
    }

    else if (j > k)
        cout << "j: " << j << " is greatest" << endl;

    else
        cout << "k: " << k << " is greatest" << endl;
}