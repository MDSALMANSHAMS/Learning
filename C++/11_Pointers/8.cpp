#include <iostream>

void increment(int &x)
{
    x++;
}

int main()
{
    int a = 5;
    increment(a);
    std::cout << "a: " << a << std::endl;
    return 0;
}
