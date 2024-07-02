#include <bits/stdc++.h>
using namespace std;

//Simple Return the Index of the min element
int rotate(vector<int> &nums)
{
    // Core concept -> Parsing this type of array: Similar to Prob5
    int ans = INT_MAX;
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[ans]>=nums[mid])
        {
            ans = mid;
        }
        // We will move to the right direction only when it is unsorted
        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int main()
{
    vector<int> v = {14,2,2, 4, 6, 8, 8, 8, 11, 13};
    cout << rotate(v);
}