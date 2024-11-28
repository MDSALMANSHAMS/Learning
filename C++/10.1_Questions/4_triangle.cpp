// Valid triangle check
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "enter a b c" << endl;
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a)
        cout << "valid triangle" << endl;

    else
        cout << "invalid triangle" << endl;
}