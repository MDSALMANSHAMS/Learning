// Take input percentage of a student and print the grade according to marks:
// 1) 81 - 100 : very good
// 2) 61 - 80 : good
// 3) 41 - 60 : avg
// 4) <= 40 : fail

#include <iostream>
using namespace std;

int main()
{
    int percentage;
    cout << "enter percentage: ";
    cin >> percentage;

    if (percentage > 100 || percentage < 0)
    {
        cout << "enter a valid percentage" << endl;
        main();
    }
    if (percentage > 80)
        cout << "very good" << endl;

    else if (percentage > 60 && percentage <= 80)
        cout << "good" << endl;

    else if (percentage > 40 && percentage <= 60)
        cout << "avg" << endl;

    else
        cout << "fail" << endl;

    // else
    // {
    //     cout << "enter a valid percentage" << endl;
    //     main();
    // }
}