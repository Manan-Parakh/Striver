#include<bits/stdc++.h>
using namespace std;

void brute()
{
    int arr[5] = {3,2,1,2,4};
    // Sort it and then return the last element
    sort(arr, arr+4);
    cout << arr[4];

    // TC -> O(n*logn) ->Quick/Merge Sort
}
void optimal(){
    int arr[5] = {3,2,1,2,4};
    
    int largest = arr[0];
    for (int i = 0; i < sizeof(arr)/4 ; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << largest;
    // TC -> O(n)
    
}
int main()
{
    brute();
    optimal();
}