#include <bits/stdc++.h>
using namespace std;

int isPossible(vector<int> &bloomDay, int m, int k, int day)
{
    // Provided the number of bouqs to make and the value of day,
    //This fxn checks if atleast m bouquets can be made or not
    int num_of_bouqs = 0;
    int cnt = 0; // Temporary Counter, when reaches k, a bouq is made
    for (int i = 0; i < bloomDay.size(); i++)
    {
        // If bloomDay[i] >=m -> Flower has Bloomed
        if (bloomDay[i] <= day)
        {
            cnt++;
            if (cnt == k)
            {
                num_of_bouqs++;
                cnt = 0;
            }
        }
        else
            cnt = 0;
    }
    if (num_of_bouqs >= m)
        return 1;
    else
        return -1;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    if (m > bloomDay.size() / k)
        return -1;
    int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(bloomDay, m, k, mid) == 1)
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
    vector<int> bloomDay = {7,7,7,7,12,7,7};
    int m =2, k=3;
    cout << minDays(bloomDay,m,k);
}