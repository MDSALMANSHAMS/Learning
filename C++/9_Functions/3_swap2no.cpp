// // Swap two numbers
// #include <iostream>
// using namespace std;

// void swap(int a, int b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
//     cout << "a = " << a << ", b = " << b;
// }

// int main()
// {
//     int a = 15, b = 6;
//     swap(a, b);
// }

#include <iostream>
using namespace std;

void fn(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << a << b << endl;
}

int main()
{
    int a = 4, b = 5;
    fn(a, b);
}
