#include<bits/stdc++.h>
using namespace std;

void bruteAB(int a[], int size, int target)
{
    int flag = 0;
    //Run 2 for loops and find the sum of all pairs inside the loop
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (a[i] + a[j] == target)
            {
                flag = 1;
                cout << "Yes" << endl;
                cout << i << j << endl;
            }
        }
    }
    if (!flag)
    {
        cout << "No";
    }
    //TC -> O(n^2)
    //SC -> O(1)

    // We can optimize it a bit by introducing a few changes like
    /*
    1. if a[i] > target, i++ as no point of going ahead since negatives arent there.
    2. For a simple yes/no, break as soon as flag becomes 1.
    */
}

void betterAB(int a[], int size, int target)
{
    // We will hash the array once -> O(n)
    // Now start parsing the array, for every element look if target - element exists or not -> O(n)

    //Hash the array -> O(n)
    
    map<int,int> mpp;
    for (int i = 0; i < size; i++)
    {
        //map stores <key,value> -> <element, index>
        mpp[a[i]] = i;
    }
    int flag = 0;
    //for each element in the array, check if target - element exist in the map
    for (int i = 0; i < size; i++)
    {
        if (mpp.find(target - a[i]) != mpp.end())
        {
            flag = 1;
            cout << i << endl;
        }
    }
    if(!flag)
        cout << "No";
    //TC -> 
}

int main()
{
    //A. Given an array and a target value, find if the array contains 2 elements such that their sum is equal to the target value given.
    //B. Given an array that has yes as the answer of A. Find the location of the 2 elements.
    int arr[] = {2,6,5,8,11};
    int target = 14;
    int size = sizeof(arr)/4;
    //bruteAB(arr,size,target);
    betterAB(arr,size,target);
}