#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &v, int target)
{
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == target)
            return mid;
        // Figure out the sorted half of the array
        if (v[mid] - v[low] >= 0) // Left Half is Sorted
        {
            // Check if target exists in the left half
            if (target >= v[low] && target < v[mid])
            {
                // Eliminate the right half
                high = mid - 1;
            }
            // Else eliminate the left half
            else
                low = mid + 1;
        }
        else // Right Half is Sorted
        {
            // Check if target exists in the right half
            if (target > v[mid] && target <= v[high])
            {
                // Eliminate the left half
                low = mid + 1;
            }
            // Else eliminate the right half
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> v = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 6;
    cout << search(v, n);
}