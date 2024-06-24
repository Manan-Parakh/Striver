#include <bits/stdc++.h>
using namespace std;

void optimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (left <= right && top <= bottom)
    {
        // Traversal in the top row, from left to right
        for (int j = left; j <= right; j++)
        {
            cout << matrix[top][j] << " ";
        }
        top++;
        // Traversal in the downward direction, right row, from to bottom, including bottom
        for (int i = top; i <= bottom; i++)
        {
            cout << matrix[i][right] << " ";
        }
        right--;

        if(top>bottom) break;
        //If top is below bottom, we do not need to print the bottom row
        //If left > right, we do not need to print left row

        // Traversal from right to left in the bottom row
        for (int j = right; j >= left; j--)
        {
            cout << matrix[bottom][j] << " ";
        }
        bottom--;
        if(left>right) break;
        // Traversal from bottom to top in the left row
        for (int i = bottom; i >= top; i--)
        {
            cout << matrix[i][left] << " ";
        }
        left++;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    optimal(matrix);
}