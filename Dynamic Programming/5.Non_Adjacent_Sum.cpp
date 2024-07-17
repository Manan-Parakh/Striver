#include <bits/stdc++.h>
using namespace std;
int house_robber(vector<int> &arr, int index, vector<int> &dp)
{
    if (index >= arr.size())
    {
        return 0;
    }
    if (index == 0 || index == 1)
    {
        dp[index] = arr[index];
        house_robber(arr, index + 1, dp);
    }
    else
    {
        // Might choose the current element, might not
        dp[index] = arr[index] + *max_element(dp.begin(), dp.begin() + index - 1);
        house_robber(arr, index + 1, dp);
    }
    return *max_element(dp.begin(), dp.end());
}
int rob(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return house_robber(nums, 0, dp);
}
int main()
{
    // Given an array of integers, return the subsequence with max sum such that no adjacent element is chosen
    vector<int> arr = {1, 2, 4, 1,3};
    cout << rob(arr);
}