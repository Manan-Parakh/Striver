#include <bits/stdc++.h>
using namespace std;

void first_try(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    //For an element, let i represent the row and j, the column
    //i,j -> j, col-i-1
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat[j][m-i-1] = matrix[i][j];
        }
    }
    //Print the new matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<< mat[i][j] << " ";
        }
        cout << endl;
    }

    //TC -> O(n*n)
    //SC -> O(n*n)
}

void swap(vector<vector<int>>& matrix, int i, int j)
{
    int temp = matrix[i][j];
    matrix[i][j] = matrix[j][i];
    matrix[j][i] = temp;
}
void rev(vector<vector<int>>& matrix, int i)
{
    for (int j = 0; j < matrix.size()/2; j++)
    {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[i][matrix.size()-j-1];
        matrix[i][matrix.size()-j-1] = temp;
    }
}
void optimal_self(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    //Take transpose of the matrix
    for (int i = 0; i < n;i++)
    {
        for (int j = i; j <n; j++)
        {
            swap(matrix, i,j);
        }
    }
    //Reverse the rows
    for (int i = 0; i < n; i++)
    {
        rev(matrix,i);
    }
    
    //Print the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< matrix[i][j] << " ";
        }
        cout << endl;
    }
    //TC-> O(n^2)
    //SC-> O(1)
}

int main()
{
    vector<vector<int>> arr;
    arr =  {{1, 2, 3,4}, {5, 6,7,8}, {9,10,11,12}, {13,14,15,16}};
    optimal_self(arr);
}