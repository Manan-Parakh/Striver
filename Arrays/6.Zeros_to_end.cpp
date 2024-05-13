#include<bits/stdc++.h>
using namespace std;

void swap(int*p , int*q){
    int temp = *p;
    *p = *q; *q = temp;
}

void shift_left(int arr[], int size, int i)
{
    // This fxn shift left: arr from index i to end
    int temp = arr[i];
    for (int j = i; j < size; j++)
    {
        arr[j] = arr[j+1];
    }
    arr[size-1] = temp;
    
}
// first_try fails to retain the order of elements
void first_try(int arr[], int size)
{
    // keep a pointer at the end that point to non zero element
    // start parsing from beginning:i and swap with j whenever we find a zero
    int j = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (i>=j)
        {
            break;
        }
        
        while (!arr[j])
        {
            j--;
        }
        if (!arr[i])
        {
            swap(arr[i],arr[j]);
        }  
    }
    // TC-> O(n)
    // SC-> O(1)
    // But this does not retain the order of elements
}

//Second try: We start with i, the moment we encounter 0, we shift the arr(i->size) 1 posn left
// Very lame... High Time Complexity
void second_try(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == 0)
        {
            int count = 0;
            do
            {
                count++;
                shift_left(arr, size, i);
            } while(!arr[i] && count< size);
        }
    }
}

void optimal(int arr[], int size)
{
    // Approach similar to that of removing duplicates...
    int j =0; // j will be sitting at the locn where non zero number shall come
    while(arr[j] != 0) j++;
    for(int i =j; i<size; i++)
    {
        if(arr[i] != 0) swap(arr[i],arr[j++]);
    }

    //TC -> O(n)
    //SC -> O(1)
}

int main()
{
    //Move all the zeros of the array to the end
    int arr[] = {1,0,0,6,4,3,0,2,5};
    int size = sizeof(arr)/4;

////first_try(arr,size);
////second_try(arr,size);
    optimal(arr,size);
    //Print the Array
    for (auto it : arr)
    {
        cout << it << ' ';
    }
       
}