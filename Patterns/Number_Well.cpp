#include<bits/stdc++.h>
using namespace std;
int main()
{
    int rows;
    cin >> rows;
    // Number Well
    /* n = 4
    1      1
    12    21
    123  321
    12344321
    */
   for (int i = 1; i <= rows; i++)
   {
    for (int j = 1; j <= 2*rows; j++)
    {
        if (j <= i)
        {
            cout << j;
        }
        else if (j > 2*rows - i )
        {
            cout << 2*rows - j +1 ;
        }
        else cout << ' ';
        
    }
    cout << endl;
   }
   
}