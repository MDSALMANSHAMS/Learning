// Display this GP - 1,2,4,8,16... upto 'n' terms.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter no. ";
    cin >> n;

    int a = 1;
    int r = 2;
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        cout << "GP is: " << a << " ";
        sum += a;
        a = a * r;
    }
    cout << " " << endl;
    cout << "sum is: " << sum << endl;
    main();
}