#include <bits/stdc++.h>
using namespace std;

int value(vector<int> &nums, int divisor)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans += ceil(float(nums[i]) / divisor);
    }
    return ans;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    // bcz threshold >= size of arr, max poss value of divisor: max element
    int low = 1, high = *max_element(nums.begin(), nums.end());
    int ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int calc_value = value(nums, mid);
        if (calc_value <= threshold)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}