#include <bits/stdc++.h>
using namespace std;

// TC -> O(N) as once calculated, the fxn calls are O(1) calls
// SC -> O(N) [Recursion Stack Space] + O(N) [dp Vector]

// Comparing with Normal Recursion
// TC(Without Dp) -> O(2^N)
int fibo_dp(int n, vector<int> &dp)
{
    cout << n << endl;
    // Base Case
    if (n <= 1)
    {
        return dp[n] = n;
    }
    // Check if value exists in fibo_dp
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fibo_dp(n - 1, dp) + fibo_dp(n - 2, dp);
}

// TC -> O(n)
// SC -> O(n) // No Recursion Stack Space
void fibo_dp_bottom_up(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        dp[n] = n;
        fibo_dp_bottom_up(n + 1, dp);
        return;
    }
    for (int i = 2; i < dp.size(); i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[dp.size() - 1];
}

// Now, we know that only last two elements are imp in Bottom Up Approach
// So we reduce the vector size to two
//TC -> O(n)
//SC ->O(1)
void optimal_fibo_dp_bottom_up(int n)
{
    vector<int> dp = {0,1};
    int ans;
    for (int i = 2; i <= n; i++)
    {
        ans = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = ans;
    }
    cout << ans;
}
void fibo(int n)
{
    // Call the rec fxn
    vector<int> dp(n + 1, -1);
    // cout << fibo_dp(n,dp) << endl;
    //fibo_dp_bottom_up(0, dp);
    optimal_fibo_dp_bottom_up(n);
}
int main()
{
    int n = 10;
    fibo(n);
}