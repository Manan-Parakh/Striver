#include<bits/stdc++.h>
using namespace std;

int brute(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        //for every element, count the freq
        int count = 0;
        for (int j = i; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count >= size/2)
        {
            return arr[i];
        }
    }
    return -1;
    
    // TC -> O(n^2)
    // SC -> O(1)
}

void better(int arr[], int size)
{
    //Hashing -> Count the freq of each element and then return the one(if exists) with freq>int(n/2)
    map<int,int> freq;

    //store <element,freq>
    for (int i = 0; i < size; i++)  //TC -> O(N*Log(N))
    {
        freq[arr[i]]++;
    }

    // Find the majority element by iterating throught the freqmap
    for (auto it = freq.begin(); it != freq.end(); ++it) //TC -> O(N)
    {
        if (it -> second > size/2)
        {
            cout << "Majority Element: " << it->first;
            return;
        }
    }
    cout << "No Majority Element!";

    //TC -> O(N*Log(N)) for storing the elements in the map + O(N) for traversing the map
    //SC -> O(N)
}

//To Optimize the Space Complexity as well
void optimal_moore(int arr[], int size)
{
    int element;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        //If count == 0, assume that the current element is the majority element
        if (count == 0)
        {
            element = arr[i];
            count++;
            continue;
        }
        if (arr[i] != element)
        {
            count--;            
        }
        else count++;
    }
    cout << element;

    //TC -> O(N)
    //SC -> O(1)
}

int main()
{
    //Given an integer array of size n, find the element that appears MORE than int(n/2) number of times
    int arr[] = {5,5,7,7,5,5,2,2,5,1,5};
    int size = sizeof(arr)/4;
    
    ////cout << brute(arr,size);
    ////better(arr,size);
    optimal_moore(arr, size);
}