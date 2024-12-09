/*
Given an integer numRows, return the first numRows of Pascal's triangle. In
Pascal's triangle, each number is the sum of the two numbers directly above
it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int numRows = 10;
    vector<vector<int>> ans(numRows);
    ans[0].push_back(1);

    for (int i = 1; i < numRows; i++)
    {
        ans[i].push_back(1);

        for (int j = 1; j < i; j++)
        {
            int num = ans[i - 1][j - 1] + ans[i - 1][j];
            ans[i].push_back(num);
        }

        ans[i].push_back(1);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
int main()
{
    int numRows = 4;
    vector<vector<int>> ans(numRows);
    ans[0].push_back(1);

    for (int i = 1; i < numRows; i++)
    {
        ans[i].push_back(1);

        // Calculate the intermediate values
        for (int j = 1; j < i; j++)
        {
            int num = ans[i - 1][j - 1] + ans[i - 1][j];
            ans[i].push_back(num);
        }

        // End each row with 1
        ans[i].push_back(1);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

*/