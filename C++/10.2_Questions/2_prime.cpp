// Prime or composite number check
#include <iostream>
using namespace std;
int main()
{
    int n = 17;
    bool flag = true;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }

    if (n == 1)
        cout << "neither prime nor composite";
    else if (flag == true)
        cout << "Prime";
    else
        cout << "Composite";
}