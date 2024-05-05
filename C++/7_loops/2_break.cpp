// Find the highest factior of a no. 'n' (other than n itself)

#include <iostream>
using namespace std;

// int main()
// {
//     int n;
//     cout << "enter n: ";
//     cin >> n;
//     int hig_fact;
//     cout << "Factors are: ";
//     for (int i = 1; i < n; i++)
//     {
//         if (n % i == 0)
//         {
//             cout << i << ", ";
//             hig_fact = i;
//         }
//     }
//     cout << " " << endl;
//     cout << "High factor is: " << hig_fact << endl;
//     main();
// }

int main()
{
    int n;
    cout << "Enter no. ";
    cin >> n;

    for (int i = n / 2; i >= 1; i--)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            break;
        }
    }
}