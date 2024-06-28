#include <bits/stdc++.h>
using namespace std;

void iterative(vector<int> &v, int target)
{
    int low = 0, high = v.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] == target)
        {
            cout << mid;
            return;
        }
        if (v[mid] < target)
        {
            // target exists on right of mid
            low = mid + 1;
        }
        else if (v[mid] > target)
        {
            high = mid - 1;
        }
        else
            break;
    }
    cout << "Does Not Exist!";
}

void recursive(vector<int> &v, int target, int low, int high)
{
    if (low >= high && v[low] != target)
    {
        cout << "DNE!";
        return;
    }
    int mid = (low + high) / 2;
    if (v[mid] == target)
    {
        cout << mid;
        return;
    }
    if (v[mid] < target)
    {
        recursive(v, target, mid + 1, high);
    }
    else if (v[mid] > target)
    {
        recursive(v, target, low, mid - 1);
    }
}

int main()
{
    vector<int> v = {3, 4, 5, 6, 9, 12, 16, 17};
    int target = 6;
    // Iterative Implementation
    iterative(v, target);
    // Recursive Implementation
    // recursive(v, target, 0, v.size() - 1);

    // TC -> O(Log2(N))
}