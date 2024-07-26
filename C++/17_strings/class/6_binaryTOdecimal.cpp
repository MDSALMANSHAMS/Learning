#include <iostream>
#include <string>
using namespace std;

int main()
{
    string binaryString = "100";
    int decimalValue = stoi(binaryString, nullptr, 2); // The base 2 tells stoi to interpret "1101" as a binary number.

    cout << decimalValue << endl;
    return 0;
}
