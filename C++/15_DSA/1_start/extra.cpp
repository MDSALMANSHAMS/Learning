// move all negarive numbers to beginning and positive to end with constant extra space.

#include <iostream>
#include <vector>
using namespace std;
void sort2(vector<int> &v)
{
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        if (v[i] < 0)
        {
            i++;
        }
        else if (v[j] > 0)
        {
            j--;
        }
        else
        {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
}
int main()
{
    vector<int> v = {1, -3, 2, -1, 3, -4, 5, -5, 7, -8};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    sort2(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
} // iska output sahi nhi aa rha hai koi bta sakta isme problem kha pr h