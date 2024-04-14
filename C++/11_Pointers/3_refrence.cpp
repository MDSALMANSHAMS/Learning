#include <iostream>
using namespace std;

int main()
{
    int x = 3;
    int *p = &x;
    cout << *p << endl;
    cout << &p << endl;
    cout << &x << endl;

    *p = 23;
    cout << x << endl;
}