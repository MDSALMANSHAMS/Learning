#include <iostream>
using namespace std;

int main()
{
    bool isRaining = false;
    bool haveUmbrella = false;

    if (isRaining || haveUmbrella) // Logical OR (||)
    {
        cout << "You can go outside." << endl;
    }
    else
    {
        cout << "It's raining and you don't have an umbrella." << endl;
    }
    return 0;
}
