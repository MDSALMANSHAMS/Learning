// Vector is a dinamic array, that can grow it's size.

#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

int main()
{
    vector<int> vect = {1, 3, 2, 4};
    sort(vect.begin(), vect.end());
    reverse(vect.begin(), vect.end());

    cout << "vect: ";
    for (int i = 0; i < 4; i++)
    {
        cout << vect[i] << "  ";
    }

    cout << endl;

    vector<int> vect_2(4, 0);
    cout << vect_2.size() << endl;
    vect_2.push_back(1);
    cout << vect_2.size() << endl;
    vect_2.pop_back();

    cout << "vect_2: ";
    for (int i = 0; i < vect_2.size(); i++)
    {
        cout << vect_2[i] << "  ";
    }
    cout << endl;
}
