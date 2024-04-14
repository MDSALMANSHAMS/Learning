// Write a program to create a calculator that performs basic arithmetic operations using switch case.

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char operation;
    cout << "enter: ";
    cin >> a;
    cin >> operation;
    cin >> b;

    switch (operation)
    {
    case '+':
        cout << a + b << endl;
        break;

    case '-':
        cout << a - b << endl;
        break;
    case '*':
        cout << a * b << endl;
        break;
    case '/':
        cout << a / b << endl;
        break;
    default:
        cout << "invalid operator" << endl;
    }
}