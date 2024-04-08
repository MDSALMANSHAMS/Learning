// print
//     *
//     *
// * * * * *
//     *
//     *

#include <iostream>
using namespace std;
int main()
{
    int n = 9;

    int target = n / 2 + 1;

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            if (i == target || j == target)
            {

                cout << "* ";
            }
            else
                cout << "  ";
        }
        cout << endl;
    }
}
