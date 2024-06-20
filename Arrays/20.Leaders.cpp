#include<bits/stdc++.h>
using namespace std;

void first_try(int arr[], int size)
{
    //O(N) approach popped in my mind
    //Iterate from the ending of the array and keep a track of max element
    int max = INT_MIN;
    vector<int> leaders;
    for (int i = size-1; i >=0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            leaders.push_back(arr[i]);
        }
    }
    //Print the leaders
    for (auto it : leaders)
    {
        cout << it << endl;
    }
    
    
}
int main()
{
    //If the all the elements on the right of a certain element X is smaller than X, then X is a leader.
    int arr[] = {10,22,12,3,0,6};
    int size = sizeof(arr)/4;
    first_try(arr,size);
}