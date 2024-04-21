#include <iostream>
using namespace std;

int main()
{
    int arr[3]; // decelaration

    arr[0] = 7; // initalization
    arr[1] = -1;
    arr[2] = 5;

    for (int i = 0; i <= 2; i++)
    {
        cout << arr[i] << endl; // printing
    }

    arr[1] = 99; // updating

    for (int i = 0; i <= 2; i++)
    {
        cout << arr[i] << endl;
    }
}