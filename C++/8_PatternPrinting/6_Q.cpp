// print
// * * * * * *
// *         *
// *         *
// * * * * * *

#include <iostream>
using namespace std;
int main()
{
    int m = 5;
    int n = 16;

    // int target = n / 2 + 1;

    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            if ((i == 1 || i == m) || (j == 1 || j == n)) //&& (j >= 2 && j <= 5))
            {

                cout << "* ";
            }
            else
                cout << "  ";
            // cout << "* ";
        }
        cout << endl;
    }
}
