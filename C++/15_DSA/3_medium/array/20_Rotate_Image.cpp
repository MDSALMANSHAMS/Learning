/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees
(clockwise). You have to rotate the image in-place, which means you have to modify the input
2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    // Transposed O (n^2)
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Swap O(n^2)
    for (int i = 0; i < matrix.size(); i++)
    {
        int k = matrix.size() - 1;
        for (int j = 0; j < matrix.size() / 2; j++)
        {
            swap(matrix[i][j], matrix[i][k - j]);
        }
    }

    // visualization
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int num : matrix[i])
        {
            cout << num << " ";
        }
    }
}
