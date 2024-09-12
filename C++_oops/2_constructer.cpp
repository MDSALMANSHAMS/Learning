#include <iostream>
#include <string>
using namespace std;

class Rectangle
{
public:
    int l;
    int b;

    Rectangle()
    {
        l = 0;
        b = 0;
    }

    Rectangle(int x, int y)
    {
        l = x;
        b = y;
    }

    Rectangle(Rectangle &r)
    {
        l = r.l;
        b = r.b;
    }
};

int main()
{
    Rectangle R1;
    cout << R1.l << " " << R1.b << endl;

    Rectangle R2(3, 4);
    cout << R2.l << " " << R2.b << endl;

    Rectangle R3(R2);
    cout << R3.l << " " << R3.b << endl;

    return 0;
}