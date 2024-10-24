/*
Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the
resulting image. To flip an image horizontally means that each row of the image is reversed. For
example, flipping [1,1,0] horizontally results in [0,1,1]. To invert an image means that each 0
is replaced by 1, and each 1 is replaced by 0. For example, inverting [0,1,1] results in [1,0,0].

Example 1:
Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]

Example 2:
Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> image = {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};

    // reverse
    for (int i = 0; i < image.size(); i++)
    {
        int first = 0, last = image[0].size() - 1;
        while (first < last)
        {
            swap(image[i][first], image[i][last]);
            first++;
            last--;
        }
    }

    // invert
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[i].size(); j++)
        {
            if (image[i][j] == 0)
                image[i][j] = 1;

            else
                image[i][j] = 0;
        }
    }

    // visualization
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[i].size(); j++)
            cout << image[i][j] << " ";
    }
}