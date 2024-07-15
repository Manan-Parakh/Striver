#include<bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    cout <<n << endl;
    if (n<=1)
    {
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
int main()
{
    cout << fibo(5);
}