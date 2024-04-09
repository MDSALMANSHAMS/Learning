#include <iostream>
using namespace std;

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "a = " << a << ", b = " << b;
}

int main()
{
    int a = 15;
    int b = 6;

    swap(a, b);
}