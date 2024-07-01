#include <bits/stdc++.h>
using namespace std;

// Understand: These are kind of template codes! -> Used in Problems...
//LeetCode Accepted Solution
vector<int> searchRange(vector<int> &v, int target)
{
    int lb = lower_bound(v.begin(), v.end(), target) - v.begin();
    int ub = upper_bound(v.begin(), v.end(), target) - v.begin() - 1;
    vector<int> ans = {-1, -1};
    if (lb == v.size() || v[lb] != target)
        return ans;
    ans[0] = lb;
    ans[1] = ub;
    return ans;
}

void first_try(vector<int> &v, int n)
{
    // Find the Lower_Bound and Upper_Bound-1
    int low = 0, high = v.size() - 1;
    int a = 0, b = v.size() - 1;
    int lb = v.size();
    int ub = v.size();

    // Lower_Bound Implementation
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] >= n)
        {
            lb = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    low = 0, high = v.size() - 1;
    // Upper_Bound Implementation
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] > n)
        {
            ub = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    // Edge Cases -> When the element isn't there
    if (v[lb] != n || lb == v.size())
    {
        lb = -1;
        ub = 0;
    }
    cout << lb << " " << ub - 1;
}

int main()
{
    vector<int> v = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 14;
    first_try(v, n);
}