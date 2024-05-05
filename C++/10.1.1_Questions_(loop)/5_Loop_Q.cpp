// Display this AP - 1,3,5,7,9...... upto 'n' terms.
// an = a + (n - 1)d

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter no. ";
    cin >> n;

    int d = 2;
    int sum = 0;
    cout << "AP is: ";

    for (int i = 1; i <= d * n; i = i + d)
    {
        cout << " " << i << ",";
        sum = sum + i;
    }
    cout << " " << endl;
    cout << "Sum is: " << sum << endl;

    main();
}