//Link: https://leetcode.com/problems/kth-missing-positive-number/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //If the missing number is outside the scope of array, i.e bigger than the last ele
        if( arr[arr.size()-1] -arr.size() < k)
        {
            return arr[arr.size()-1] + k - arr[arr.size()-1] + arr.size(); 
        }
        if(arr[0] > k) return k;

        int low = 0, high = arr.size()-1;
        int ans = -1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int me_behind = arr[mid] - (mid+1); //Missing elements behind
            if(me_behind >= k)
            {
                ans = mid;
                high = mid-1;
            }
            else if(me_behind < k)
            {
                low = mid+1;
            }
        } 
        //ans is pointing to the element behind which our kth missing element lies
        return (arr[ans]) - (arr[ans] - ans -1 - k+1);
    }
};