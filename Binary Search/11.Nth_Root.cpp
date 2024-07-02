#include <bits/stdc++.h>
using namespace std;

//Compiler Error, but ok
//Use pow instead of loop -> O(logn)
int NthRoot(int n, int m)
{
    int low = 0, high = m;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (pow(mid, n) == m)
        {
            return mid;
        }
        else if (pow(mid, n) > m)
            high = mid - 1;
        else if (pow(mid, n) < m)
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    cout << NthRoot(4, 81);
}