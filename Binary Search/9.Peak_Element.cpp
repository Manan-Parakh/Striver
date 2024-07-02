#include <bits/stdc++.h>
using namespace std;
//Solved it in first try
int findPeakElement(vector<int> &v)
{
    if (v.size() == 1)
        return 0;
    if (v[0] > v[1])
        return 0;
    if (v[v.size() - 1] > v[v.size() - 2])
        return v.size() - 1;
    int low = 1, high = v.size() - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])
            return mid;

        if (v[mid + 1] > v[mid])
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    vector<int> v = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(v);
}