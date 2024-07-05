#include <iostream>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;
    std::cout << *(p + 2) << std::endl;
    return 0;
}
