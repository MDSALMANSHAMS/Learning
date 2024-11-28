// Given the length and breadth of a rectangle, write a program
// to find whether the area of the rectangle is greater than its perimeter.

#include <iostream>
using namespace std;
int main()
{
    int length, breadth;
    cout << "enter length: ";
    cin >> length;
    cout << "enter breadth: ";
    cin >> breadth;

    int area = length * breadth;
    int perimeter = 2 * (length + breadth);

    if (area > perimeter)
        cout << "area is greater" << endl;
    else
        cout << "area is smaller" << endl;
}