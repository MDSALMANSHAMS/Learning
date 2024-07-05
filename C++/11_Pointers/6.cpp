#include <iostream>

int main()
{
    int a = 5;
    int b = 10;
    int *p = &a;
    *p = b;
    std::cout << "a: " << a << ", b: " << b << std::endl;
    return 0;
}
