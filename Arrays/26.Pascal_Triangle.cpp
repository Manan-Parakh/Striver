#include <bits/stdc++.h>
using namespace std;

void element_rc(int r, int c)
{
    // The value will be r-1 C c-1
    // bcz c <= r
    long long prod = 1;
    for (int i = 1; i <= c - 1; i++)
    {
        prod = prod * (r - i) / i;
    }
    cout << prod << " ";

    // TC -> O(row)
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pt;
    // generate a row and append it to the pt vector
    for (int row = 0; row < numRows; row++)
    {
        int prod = 1;
        vector<int> temp;
        temp.push_back(1);
        for (int col = 1; col <= row; col++)
        {
            prod = prod * (row - col + 1) / (col);
            temp.push_back(prod);
        }
        pt.push_back(temp);
    }
    return pt;
}

int main()
{
    // Pascal's Triangle
    // Problem-1: Given Row r and Column c, give the integer at that position
    int r, c;
    cin >> r >> c;
    // element_rc(r,c);

    // Problem-2: Given Row r, print the rth row
    // Observation: rth row has r elements
    /*
    If we start the row and column indexing with 0, element at rc becomes rCc
    so to print a row, we simply need to multiply certain terms to print the complete row
   */
    int prod = 1;
    for (int i = 0; i <= r; i++)
    {
        cout << prod << " ";
        prod = prod * (r - i) / (1 + i);
    }
    cout << endl;

    // Problem-3: Given total_row = r, print the Pascal's Triangle upto rth row
    vector<vector<int>> ans = generate(r);
    //Print the ans
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";           
        }
        cout << endl;
    } 
}