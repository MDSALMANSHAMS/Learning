
#include <iostream>
using namespace std;

void change(int x[])
{
    x[0] = 999;
}

int main()
{
    int arr[5] = {6, 3, 33, 2, 86};

    for (int i = 0; i <= 4; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    change(arr);

    for (int i = 0; i <= 4; i++)
    {
        cout << arr[i] << " ";
    }
}