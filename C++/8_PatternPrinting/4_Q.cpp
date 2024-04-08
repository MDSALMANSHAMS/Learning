// print
// ****
// ***
// **
// *

#include <iostream>
using namespace std;
int main()
{
    int m = 4;

    for (int i = m; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << "*";
        }

        cout << endl;
    }
}
