// Arrays are pass by reference

#include <iostream>
using namespace std;

void change(int x[])
{
    x[0] = 10;
}

int main()
{
    int arr[] = {1, 2, 3};
    cout << arr[0] << endl;
    change(arr);
    cout << arr[0] << endl;
}