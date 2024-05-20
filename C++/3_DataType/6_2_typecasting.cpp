#include <iostream>
using namespace std;

int main()
{
    int i = 5;
    cout << i / 2 << endl;

    float j = (float)i; // typecasting
    cout << j / 2 << endl;

    string a = "9";
    int b = stoi(a); // stof
    cout << b / 2 << endl;
}
