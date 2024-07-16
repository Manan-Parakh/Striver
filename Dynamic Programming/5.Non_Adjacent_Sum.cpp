#include <bits/stdc++.h>
using namespace std;

int house_robber(vector<int> &arr, int index)
{
    if (index >= arr.size())
    {
        return 0;
    }
    return max(arr[index] + house_robber(arr,index+2), house_robber(arr,index+1));
}
int main()
{
    //Given an array of integers, return the subsequence with max sum such that no adjacent element is chosen
    vector<int> arr = {1,2,4,1};
    cout << house_robber(arr,0);
}