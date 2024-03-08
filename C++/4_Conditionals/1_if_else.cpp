#include <iostream>
using namespace std;

// int main()
// {
//     int i;
//     cout << "Enter your no.: ";
//     cin >> i;

//     if (i == 0)
//         cout << "zero" << endl;

//     if (i % 2 == 0)
//         cout << i << " is even" << endl;

//     else
//         cout << i << " is odd" << endl;
// }

int main()
{
    int i;
    cin >> i;

    if (i >= 0)
    {
        cout << i;
    }
    else
    {
        cout << -i;
    }
}