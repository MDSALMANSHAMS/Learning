// print
//    *
//   **
//  ***
// ****

#include <iostream>
using namespace std;
int main()
{
    int m = 4;

    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= m; j++)
        {
            if (i + j >= 5)
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
