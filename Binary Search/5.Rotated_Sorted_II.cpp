#include <bits/stdc++.h>
using namespace std;
bool search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return 1;
        // Problem Arises when ele at low, mid and high -> same
        // But not equal to target
        // So we trim down the search space to eliminate this problem
        while ((low < high && nums[low] == nums[mid]) && nums[mid] == nums[high])
        {
            low = low + 1;
            high = high - 1;
        }
        // Left Half is Sorted
        if (nums[mid] >= nums[low])
        {
            // If target exists in left half, eliminate the right half
            if (target >= nums[low] && target < nums[mid])
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        else // Right Half is sorted
        {
            if (target <= nums[high] && target >= nums[mid])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
    return 0;

    //TC-> O(log2(N)) ->Average and Best and O(N)->Worst
}

int main()
{
    vector<int> v = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 6;
    cout << search(v, n);
}