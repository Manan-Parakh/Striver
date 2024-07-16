#include <bits/stdc++.h>
using namespace std;

long long int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}
int brute(int n)
{
    int ways = 0;
    // p: number of single steps
    for (int p = 0; p <= n; p++)
    {
        if (p + 2 * ((n - p) / 2) != n)
        {
            continue;
        }
        int q = (n - p) / 2;
        // Calculate (p+q), p and q factorial
        long long a = fact(p + q);
        long long b = fact(p);
        long long c = fact(q);
        ways += (a / b) / c;
    }
    return ways;
}

int brute_dp(int n)
{
    // Implementing DP
    // Factorial Calculation: Max Value to Calculate: n!
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = i * dp[i-1];
    }
    long long ans = 0;
    for (int p = 0; p <= n; p++)
    {
        if (p + (n - p) / 2 * 2 != n)
        {
            continue;
        }
        int q = (n - p) / 2;
        // We need p+q, p,q factorial
        // Implementing the BottomsUp Approach
        ans += (dp[p + q] / dp[p]) / dp[q];
        cout << p << " " << q << " "<<ans<< endl;
    }
    return ans;
}

int rec1(int n, int stairs)
{
    //n -> total number of stairs
    //stairs -> stairs climbed: initially zero
    if (n == stairs)
    {
        //reached n, so this is a distinct path
        return 1;
    }
    if (stairs > n)
    {
        //went beyond n
        return 0;
    }
    //suppose we climb 1 stair
    return rec1(n,stairs+1) + rec1(n,stairs+2);
}

int rec1_dp(int n)
{
    vector<int> dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
    for (int i = 2; i <=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n = 10;
    // cout << brute(10);
    //cout << brute_dp(10);
    cout << rec1_dp(10);
}