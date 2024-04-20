#include <iostream>
using namespace std;
int main()
{
    int x = 3, y, z;
    y = x = 10; // right to left
    z = x < 19; // z will be boolean value

    cout << x << " " << y << " " << z;
}