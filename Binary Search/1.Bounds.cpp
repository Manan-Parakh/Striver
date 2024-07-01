#include <bits/stdc++.h>
using namespace std;

void lower(vector<int>& v, int n)
{
    int ans = v.size(); //Default Answer
    int low = 0, high = v.size()-1;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if (v[mid]>=n)
        {
            ans = mid; //As it is a Probable answer
            high = mid-1;
        }
        else if (v[mid]<n)
        {
            low = mid+1;
        }
    }
    cout << ans;
    //TC-> O(log2N)

    //Using STL
    //lower_bound returns an iterator, so to get index, do the following
    int lb = lower_bound(v.begin(), v.end(),n) - v.begin();
    cout << lb;
}

void upper(vector<int>& v, int n)
{
    int ans = v.size(); //Default Answer
    int low = 0, high = v.size()-1;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if (v[mid]>n)
        {
            ans = mid; //As it is a Probable answer
            high = mid-1;
        }
        else if (v[mid]<=n)
        {
            low = mid+1;
        }
    }
    cout << ans;
    //TC-> O(log2N)

    //Using STL
    //lower_bound returns an iterator, so to get index, do the following
    int ub = upper_bound(v.begin(), v.end(),n) - v.begin();
    cout << ub;

}
int main()
{
    //lower_bound(x) -> smallest index such that arr[index] >= x
    vector<int> v = {3,5,8,15,19};
    int n = 8;
    lower(v,n);
    upper(v,n);
}