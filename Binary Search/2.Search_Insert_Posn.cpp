#include <bits/stdc++.h>
using namespace std;

void sip(vector<int>& v, int n)
{
    //Search Index Position
    int low = 0, high = v.size()-1;
    int ans = 0;

    while (low<=high)
    {
        int mid = (low+high)/2;
        if (v[mid]<n)
        {
            ans = mid+1;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout << ans;   
}
int main()
{
    vector<int> v = {1,2,4,7};
    int n = 3;
    sip(v,n);
}