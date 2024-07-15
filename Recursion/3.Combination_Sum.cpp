#include <bits/stdc++.h>
using namespace std;

void rec(vector<int>& arr, vector<int>& a, int index, int target)
{
    //Base Condition
    if (target <0 || index >= arr.size())
    {
        //Sum exceeded
        return;
    }
    if (target ==0)
    {
        
        //Print the array
        for (auto it : a)
        {
            cout << it;
        }
        cout << endl;
        return;
    }
    //Take the element at index again
    a.push_back(arr[index]);
    rec(arr, a, index, target-arr[index]);

    //Do not take the index element again
    a.pop_back();
    rec(arr, a, index+1, target);
}

void comb_sum(vector<int>& arr, int sum)
{
    vector<int> a = {};
    rec(arr, a, 0, sum);
}
int main()
{
    //Array with unique digits and a sum will be given
    //Return combination of digits (repetetion allowed) to form the sum
    vector<int> arr = {2,3,5,7};
    int sum = 7;
    sort(arr.begin(), arr.end());
    comb_sum(arr,sum);
}