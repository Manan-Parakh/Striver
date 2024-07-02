#include <bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x)
{
    // Your code goes here
    long long int low = 0, high = x;
    long long int sqrt;

    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        if (mid * mid == x)
            return mid;
        if (mid * mid > x)
        {
            high = mid - 1;
        }
        else if (mid * mid < x)
        {
            // mid is a probable answer
            sqrt = mid;
            low = mid + 1;
        }
    }
    return sqrt;
}

int main()
{
    cout << floorSqrt(0);
}