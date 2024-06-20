#include<bits/stdc++.h>
using namespace std;

//First_try does not work.... here just to get an idea of some approach
//Maybe useful in some other place.... BUT NOT HERE!
void rotate_1_right(int arr[], int size, int low)
{
    //rotate the portion of array from index low to size-1 to the right by 1 place
    int temp = arr[size-1];
    for (int i = size-1; i>low; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[low] = temp;
}
void first_try(int arr[], int size)
{
    //Find the element where the ascending order from the back breaks
    for (int i = size-1; i>=0; i--)
    {
        if (arr[i-1] < arr[i])
        {
            rotate_1_right(arr,size,i-1);
            break;
        }
    }
    //print the array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }   
}

void brute()
{
    /*
    Generate all the perms -> Recursion
    Linear Search to find the posn of given array position
    Return the next perm
    TC -> Estimated: At Minimum -> O(N! * N)
    */
}

void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void optimal(int arr[], int size)
{
    //Find the breaking point -> i points to the first element that breaks the ascending order from the back, i.e here i will point to the location of '1'.
    
    int bp = 0; //bp -> breaking point
    for (int i = size-1; i >0; i--)
    {
        if (arr[i-1] < arr[i])
        {
            bp = i-1;
            break;
        }
    }
    //swap the element at the breakpoint with the lowest possible number in the right half of the array that is greater than the element at breakpoint
    for (int i = size-1; i >bp; i--)
    {
        if (arr[i] > arr[bp])
        {
            swap(arr[i], arr[bp]);
            break;
        }
    }

    //sort the right portion to get the lowest possible value ahead
    if (bp==0) //Last permutation -> Set to Initial Permutations
    {
        reverse(arr,arr+size);
    }
    else reverse(arr+bp+1, arr+size);
    
    //print the array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    //TC -> O(N) + O(N) + O(N*Log(N))
    //bp + finding swap element + sort

    
}

int main()
{
    int arr[] = {5,4,3,2,6,7};
    int size = sizeof(arr)/4;
    ////first_try(arr,size);

    optimal(arr,size);
}