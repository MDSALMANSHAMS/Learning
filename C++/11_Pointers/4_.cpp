#include <iostream>

int main()
{
    int a = 5;
    int b = 10;
    int *p1, *p2;

    p1 = &a;
    p2 = &b;
    *p1 = *p2;
    *p2 = *p1;

    std::cout << "a: " << a << ", b: " << b << std::endl;

    return 0;
}
