/*
Write a generator function that returns a generator object which yields the fibonacci sequence.
The fibonacci sequence is defined by the relation Xn = Xn-1 + Xn-2. The first few numbers of the
series are 0, 1, 1, 2, 3, 5, 8, 13.

Example 1:
Input: callCount = 5
Output: [0,1,1,2,3]
Explanation:
const gen = fibGenerator();

Example 2:
Input: callCount = 0
Output: []
Explanation: gen.next() is never called so nothing is outputted
*/

#include <iostream>
#include <vector>
using namespace std;

int gen_fib(int callCount)
{
    if (callCount == 0)
        return 0;

    if (callCount == 1)
        return 1;

    int ans = gen_fib(callCount - 1) + gen_fib(callCount - 2);

    return ans;
}

int main()
{
    int callCount = 8;
    vector<int> arr = {};

    for (int i = 0; i < callCount; i++)
    {
        arr.push_back(gen_fib(i));
    }

    for (int num : arr)
    {
        cout << num << " ";
    }
}
