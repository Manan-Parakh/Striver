#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Left Triangle
    /* n=3

    *
    **
    ***
    **
    *

    */
   int rows;
   cin >> rows;

   for (int i = 0; i < 2*rows-1; i++)
   {
    // In the Upper Half
    if (i < rows)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
    }
    // In the bottom half
    else
    {
        for (int j = 0; j < 2*rows - i -1; j++)
        {
            cout<< '*';
        }
    }
    cout << endl;
   }   
}