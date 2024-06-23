#include <bits/stdc++.h>
using namespace std;

void brute()
{
    /*
    Traverse the array, whenever we encounter a zero, mark all the 1s in the corresponding rows and cols as -1 and leave the original zeros as it is. Do it in the complete array, and at last, set all -1 as zeros as well.

    TC -> O(n*m) for traversing, now for each zero encuntered, O(n+m) + O(n*m) at last
    SC -> O(1)
    */
}
// First_try comes out to be the better one. Yayy!
void first_try(int arr[4][4], int n, int m)
{
    /*
    In order to set a row/col as zero, we need atleat one zero there, once we find a zero in a row/column, no need to parse it again.
    Simply store the row/col number and skip it in the next iterations
    At last -> Convert all elements of rows/cols collected as zero

    Define 2 fxns -> Markrow and Markcol -> places -1 in place of "1".

    TC -> O(n*m)*O(n+m) for parsing and placing -1,  O(n*m) for converting
    SC -> O(m+n)
    */
    int cols[m] = {0};
    int rows[n] = {0};

    // Get the rows and cols that will become zero ->O(n*m)
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (arr[row][col] == 0)
            {
                rows[row] = 1;
                cols[col] = 1;
            }
        }
    }

    // Set them zero -> O(n*m)
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (rows[row] == 1 || cols[col] == 1)
            {
                arr[row][col] = 0;
            }
        }
    }

    // Print the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }

    // TC -> O(n*m) + O(n*m)
    // SC -> O(n+m)
}

void optimal(int arr[3][5], int n, int m)
{
    // We are doing O(n^2) for a 2d array, we can't get any better
    // So we focus on the Space Complexity -> O(m+n) in better one
    // To bring it down to O(1)... Instead of taking seperate matrices for cols and rows, we know that, if a row/column will become zero, then it's first element will too.
    // So treat the first row and column itself to mark if they will become zero or not

    // Bcz the point 0,0 is common... we use it to serve the purpose for rows and introduce a var for col0 and use the rest of row 1 for col marking
    int col0 = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                // if col0 has to be made zero, we need to alter col0
                if (j == 0)
                {
                    col0 = -1;
                }
                else
                    arr[0][j] = -1;
                arr[i][0] = -1; // Marking for the row
            }
        }
    }
    // Fill the zeros upwards from the bottom right corner in right to left fashion leaving the first row and column untouched
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = m - 1; j > 0; j--)
        {
            // For elements in col 1, col0 will tell whether to fill it with zero or not
            if (arr[i][0] == -1 || arr[0][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
    // Now for the first row and column
    // Deal with row0
    for (int j = m-1; j >=0; j--)
    {
        if ((arr[0][j] == -1) || (arr[0][0] == -1))
        {
            arr[0][j] = 0;
        }
    }
    // Deal with col0 now
    // Fill the col0 with zeros
    for (int i = 0; i < n; i++)
    {
        if ((col0 == -1) || arr[i][0] == -1)
        {
            arr[i][0] = 0;
        }
    }

    // Print the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}
int main()
{
    // Given an n*m Binary matrix-> With 0/1 only.
    // Set the rows and columns of the PRE_EXISTING zeros as zeros.
    int arr[3][5] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1};
    optimal(arr, 3, 5);
}