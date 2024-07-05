#include <iostream>

void func(int &x)
{
    x = 20;
}

int main()
{
    int a = 10;
    func(a);
    std::cout << "a: " << a << std::endl;
    return 0;
}
