// print
// 1234
// 1234
// 1234

#include <iostream>
using namespace std;
int main()
{
    int m = 6;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
