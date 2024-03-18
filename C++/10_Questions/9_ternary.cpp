// Given a point (x,y), write a program to find out if it lies in the which quadrant.

#include <iostream>
using namespace std;

// Ternary operator
int main()
{
    int x, y;
    cout << "enter x, y: " << endl;
    cin >> x >> y;

    (x == 0 && y == 0) ? cout << "At the origin" << endl : (x == 0 && y != 0) ? cout << "Y-axis" << endl
                                                       : (x != 0 && y == 0)   ? cout << "X-axis" << endl
                                                       : (x > 0 && y > 0)     ? cout << "1st quadrant" << endl
                                                       : (x < 0 && y < 0)     ? cout << "3rd quadrant" << endl
                                                       : (x > 0 && y < 0)     ? cout << "4th quadrant" << endl
                                                                              : cout << "2nd quadrant" << endl;
}

// if else
// int main()
// {
//     int x, y;
//     cout << "enter x, y: " << endl;
//     cin >> x >> y;

//     if (x == 0 && y == 0)
//         cout << "at the origin" << endl;

//     else if (x == 0 && y != 0)
//         cout << "y-axis" << endl;

//     else if (x != 0 && y == 0)
//         cout << "x-axis" << endl;

//     else if (x > 0 && y > 0)
//         cout << "1st quad." << endl;

//     else if (x < 0 && y < 0)
//         cout << "3rd quad." << endl;

//     else if (x > 0 && y < 0)
//         cout << "4th quad." << endl;

//     else if (x < 0 && y > 0)
//         cout << "2nd quad." << endl;
// }
