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

int efficient(vector<int>& arr)
{
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i>1)
        {
            take += prev2;
        }

        int not_take = 0 + prev;
        
        int curi = max(take,not_take);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
int main()
{
    // Given an array of integers, return the subsequence with max sum such that no adjacent element is chosen
    vector<int> arr = {1, 2, 4, 1,3};
    cout << rob(arr);
    cout << efficient(arr);
}