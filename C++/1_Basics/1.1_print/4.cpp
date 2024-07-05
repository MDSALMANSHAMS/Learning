#include <iostream>

int main()
{
    int x = 10;
    {
        int x = 20;
        std::cout << "Inner x: " << x << std::endl;
    }
    std::cout << "Outer x: " << x << std::endl;
    return 0;
}
