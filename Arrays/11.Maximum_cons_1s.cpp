#include<bits/stdc++.h>
using namespace std;

void brute(int arr[], int size)
{
    //We take two var, maxcount and count, count is used in the loop to count the number of ones that occur continously locally while maxcount stores the max value of count achieved.
    int count = 0, maxcount = 0;
    for (int i = 0; i < size; i++)
    {
        count = 0;
        while (arr[i] == 1)
        {
            count++;
            i++;
        }
        if (count > maxcount)
        {
            maxcount = count;
        }
    }
    cout << maxcount;
    //TC -> O(n) as each element is parsed through only once
    //SC -> O(1)
}

int main()
{
    //given an array, find the number of maximum consecutive ones
    int arr[] = {0,0,1,1,1,0,0,1,1,0,1,1,0,1,1,1,1};
    int size = sizeof(arr)/4;
    brute(arr,size);
}