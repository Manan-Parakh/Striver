#include<bits/stdc++.h>
using namespace std;

void brute()
{
    //Standard Sorting
    //Merge Sort -> TC: O(N*log(N)), SC-> O(n)
}
void better()
{
    //Count the number of 0,1 and 2s.
    //Manually fill the array
    //TC-> O(2n), SC-> (1)
}

void first_try(int arr[], int size)
{
    //Our Goal: To push 0s to the left and 2s to the right extreme.
    // Whenever we encounter 0, rotate the left side of array, including 0, right by 1 posn, the zero of the right end moves to the left extreme.
    //Similarly for every 2 we encounter, move the right side of the array left by 1 posn.

    //TC-> O(n) for looping the array once
    //TC -> O(m*p) for shifting by 1 posn. where m is the number of elements to be shifted and p is the number of shifts
}

void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void optimal_dnf(int* arr, int size)
{
    // [0,low-1] : all 0
    // [low, mid-1] : all 1
    // [mid,high] : unsorted
    // [high+1, n-1] : all 2
    
    //Initially the whole array is assumed to be unsorted
    int low = 0;
    int mid = 0;
    int high = size-1;
    //Parse through the array
    while (mid <= high)
    {
        //Case 1: arr[mid] == 0; swap arr[low] and arr[mid] and low++, mid++
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (int i = 0; i<size; i++)
    {
        cout << arr[i] << endl;    
    }
    //TC -> O(n)
    //SC -> O(1)
}

int main()
{
    //Sort an array that contains 0,1,2s only.
    int arr[] = {0,1,2,0,1,2,1,2,0,0,0,1,0,1};
    int size = sizeof(arr)/4;
    optimal_dnf(arr,size);
}