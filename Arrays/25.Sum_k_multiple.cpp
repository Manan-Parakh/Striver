#include <bits/stdc++.h>
using namespace std;

void optimal(vector<int>& arr, int k)
{
    //Use the concept of prefix sum
    //Number of sub-arrays ending at particular element(prefix_sum = s) and has a sum = k is equal to the number of times prefix sum behind became s-k
    //Store the prefix-sums in a map, <psum,count>
    map<int,int> ps;
    ps[0] = 1;
    int sum = 0;
    int count= 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        count += ps[sum-k];
        ps[sum]++;
    }
    cout << count;

    //TC -> ordered map: O(N*Log(N))
    //SC -> O(n)
}

int main()
{
    //Given an array, find the number of subarrays that has sum = k
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    optimal(arr,k);
}