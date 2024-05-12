#include<bits/stdc++.h>
using namespace std;

int main(){

    int rows;
    cin >> rows;
    /*
    //For n rows -> 2n+1 stars in nth row, center aligned
    //    *    
    //   ***
    //  ***** 
    for (int i = 0; i < rows; i++)
    {
        for (int j = 1; j <= 2*rows+1; j++)
        {
            if (j >= rows - i && j <= rows +i)
            {
                cout << '*';
            }
            else
                cout << ' ';
        }
        cout << endl;
    }
    */

    /*
   //Reverse Pattern
   for (int i = 0; i < rows; i++)
   {
    for (int j = 1; j < 2*rows +1; j++)
    {
        if (j > i && j < 2*rows -i)
        {
            cout <<'*';
        }
        else cout << ' ';
    }
    cout << endl;
   }
    */

   /* 
   Combined Pattern 
   for n = 3
     *
    ***
   *****
    ***
     *
    */
    for (int i = 0; i < 2*rows; i++)
    {
        for (int j = 1; j < 2*rows+1; j++)
        {
            if (i < rows)
            {
                // Print the First Pattern
                if (j >= rows - i && j <= rows+i )
                {
                    cout << '*';
                }
                else cout << ' ';
            }

            else{
            if (j> i-rows && j < 2*rows - i + rows)
            {
                cout << '*';
            }
            else cout << ' ';
            }
        }
        cout << endl;
    }
    

}