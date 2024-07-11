#include <iostream>
using namespace std;

int squar(int a)
{
    return a * a;
}

int main()
{
    int x;

    cout << "enter your no.: ";
    cin >> x;
    cout << "Squar: " << squar(x) << endl;
}

// test