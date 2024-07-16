#include <bits/stdc++.h>
using namespace std;
int fj(vector<int> &height, int n)
{
    //From stair i it can go to either i+1 or i-1th stair\
    //s denotes the current stair

    vector<int> dp(n, -1);
    dp[0] = 0;                          // Energy req to go to 1st stair
    dp[1] = abs(height[0] - height[1]); // Energy req to go to 2nd stair

    for (int i = 2; i < n; i++)
    {
        // energy req to go to ith stair
        // Either it will come from i-1 or i-2th stair
        dp[i] = min(dp[i-1]+abs(height[i - 1] - height[i]), dp[i-2] + abs(height[i - 2] - height[i]));
    }
    return dp[n - 1];
}

int main()
{
    vector<int> height = {10, 20, 30, 10};
    int n = 4;
    cout << fj(height, n);
}