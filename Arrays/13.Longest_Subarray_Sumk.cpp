#include<bits/stdc++.h>
using namespace std;

void brute()
{
    /*
    for(i->size)
    {
        for(j=i ->size)
        {
            //subarray : from i to j
            //3rd for loop to sum up the subarray
            for(l: i->j) sum;
            if (sum == k) len = max(len,j-i+1)
        }
    }
    */

   //TC -> O(n^3) not exactly but somewhat like this
   //SC -> O(1)
    
}
void first_try_brute(int arr[], int size, int k)
{
    //Variable sum stores the local sum and 2 indices keep a track of the current subarray
    // if sum is reached, store the indices so that we can print the subarray
    int sum = 0;
    int a = 0, b = 0, amax = 0, bmax = 0;
    int len = 0;

    for (int i = 0; i < size; i++) //TC -> O(n)
    {
        sum = 0;
        int j = i;
        while (sum < k) // TC -> O(n)
        {
            sum = sum + arr[j++];
        }
        if (sum == k)
        {
            len = max(len,j-i);
        }
    }
    cout << "len: " << len;

    //TC -> O(n^2)
    //SC -> O(1)
}

//better is optimal when negatives are there
void better(int a[],int size, long long int k)
{
    // k-> sum
    map<long long int, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < size; i++)
    {
        sum += a[i];
        //Check if the whole of the current subarray has sum k
        if (sum == k)
        {
            maxLen = max(i+1, maxLen);
        }
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(len, maxLen);
        }
        // To tackle the problem of zeros reducing the array size, we want the rem to be as left as possible... not updating the index with zero
        if (preSumMap.find(rem) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    cout << "Max Length:" << maxLen;    

    //This code is optimal when negatives are there, but only the better one when negs aren't there... So it can be optimized further for the cases where negs are not there

    //TC -> O(n*log(n)) : ordered map
    //TC -> O(n*1) : unordered map..... but if collisions are there, O(n*n)
    //SC -> O(n) : All the prefixsum stored
    // We are definitely Iterating the array -> N 
}

//optimal when negatives aren't there
void optimal(int a[], int size, long long k)
{
    //2 pointer + greedy approach
    int i = 0, j = 0;
    long long sum = a[0];
    int maxlen = 0;
    while (i <= j && j < size)
    {
        if (sum == k)
        {
            maxlen = max(maxlen, j-i+1);
            //Move j ahead
            sum += a[++j];
        }
        else if (sum < k)
        {
            if (j<size-1)
            {
                j++;
                sum = sum + a[j];
            }
            else break;

        }
        else if (sum > k)
        {
            sum = sum - a[i];
            i++;
        }
    }
    cout << "Max Length:" << maxlen;
    // TC -> O(n)
    // SC -> O(1)
}
int main()
{
    //Given an array with pos inputs only, find the longest subarray with sum k
    //subarray -> continous block
    //subsequence -> not a continous block
    int arr[] = {1,1,0,0,1,-1,+1,0,0,0,3,1,3,0,1,1,1};
    int size = sizeof(arr)/4;
    long long int k =3;
    //first_try_brute(arr,size,k);
    //better(arr,size,k);
    optimal(arr,size,k);
}