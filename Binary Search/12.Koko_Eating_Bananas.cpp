#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int hours(vector<int> &piles, int k)
{
    int ans = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        ans += ceil(float(piles[i]) / k);
    }
    return ans;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    // Find the max poss value of k -> max element of piles
    sort(piles.begin(), piles.end());
    int low = 1, high = piles[piles.size() - 1];
    int ans = h;

    while (low <= high)
    {
        // max number of hours it has -> h
        int mid = low + (high - low) / 2;
        int req_hours = hours(piles, mid);
        if (req_hours == h) return mid;
        if (req_hours < h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout << minEatingSpeed(piles,h);
}