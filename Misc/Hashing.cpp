#include<bits/stdc++.h>
using namespace std;
int main()
{
    // n: array size
    int n;
    cin >> n;

    int arr[n];
    map<int,int> mpp;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }
    
    // Iterate in the map
    for (auto it: mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }
    

    // count = number of entries to check
    int count;
    cin >> count;
    while(count--){
        int m;
        cin >> m;
        cout << mpp[m] << endl;
    }
    
}