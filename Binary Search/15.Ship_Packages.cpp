#include <bits/stdc++.h>
using namespace std;

int days_req(vector<int> &weights, int wcap)
{
    // mid is the wt capacity given to us
    int days = 0;
    int sum = weights[0];
    for (int i = 1; i < weights.size(); i++)
    {
        if (sum + weights[i] < wcap)
        {
            // This Product can be loaded
            sum += weights[i];
        }
        else if (sum + weights[i] == wcap)
        {
            // This Product can be loaded but it is the last for this day
            sum = 0;
            days++;
        }
        else if (sum + weights[i] > wcap)
        {
            // This element can't be added
            days++;
            sum = weights[i];
        }
    }
    if (sum > 0)
        days++;
    return days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    // Bcz the order of weights matter, we should not sort it.
    int low = *max_element(weights.begin(), weights.end());
    int high = low * weights.size();
    int ans = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int req_days_mid = days_req(weights, mid);
        if(req_days_mid <=c days)
        {
            // We can try to increase the wcap
            high = mid - 1;
            ans = mid;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    vector<int> weights = {3,2,2,4,1,4};
    int days = 3;
    cout << shipWithinDays(weights, days);
}