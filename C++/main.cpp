/*
[1, 2, 3, 4, 5], [6, 7, 8, 9, 0]
[2, 4, 5, 1, 3], [7, 9, 0, 6, 8]
*/

#include <iostream>
#include <vector>
using namespace std;

void random_fn(vector<int> &vet)
{
    for (int i = 0; i < vet.size() / 2; i++)
    {
        int temp = vet[i];
        vet[i];
    }
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5}, b = {6, 7, 8, 9, 0};

    random_fn(a);
    random_fn(b);

    for (int num : a)
    {
        cout << num << " ";
    }

    for (int num : b)
    {
        cout << num << " ";
    }
}
