#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);   
        }
        else temp.push_back(arr[right++]);
    }
    while (left <= mid)
    {
        temp.push_back(arr[left++]); 
    }
    while(right <= high){
        temp.push_back(arr[right++]); 
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
    
}

void merge_sort(vector<int> &arr, int low, int high)
{
    if ( low == high){
        return;
    }
    int mid = (low+high) /2 ;
    merge_sort(arr, low, mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
    return;
}
int main()
{
    vector<int> arr = {2,3,4,1,6,5,7};

    merge_sort(arr,0, arr.size() -1);

    for (auto it: arr)
    {
        cout << it << ' ';
    }
    
}