#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &v)
{
    if(v.size() == 1 || v[0] != v[1]) return v[0];
    if(v[v.size()-1] != v[v.size()-2]) return v[v.size()-1];

    int low = 1, high = v.size() - 2;
    while(low<=high)
    {
        cout << low << high << endl;
        int mid = (low+high)/2;
        if(v[mid] != v[mid-1] && v[mid] != v[mid+1]) return v[mid];

        if(v[mid] == v[mid+1])
        {
            if(mid%2 == 0) low = mid+1;  // (even,odd) pair
            else high = mid-1;
        }
        else if(v[mid] == v[mid-1])
        {
            if(mid%2 ==0) high = mid-1; //(odd,even) pair
            else low = mid+1;
        }
    }
    return -1;
}
int main()
{
    vector<int> v = {1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(v);
}