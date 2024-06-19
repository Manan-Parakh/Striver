#include<bits/stdc++.h>
using namespace std;

void brute()
{
    //Extract all the +/- elements and then put them back
    //TC -> for parsing once -> O(n) and then O(n) for putting things back
    //SC -> O(n)
}

void optimal(int arr[], int size)
{
    //To Reduce the TC from 2N to N, we will try to do it in one go
    //Keep two indices -> pos and neg, pos elements -> Even place
    //Parse through the array and place the elements in their respective place in the new answer array
    int pos = 0;
    int neg = 1;
    int ans[size] = {0};
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            ans[pos] = arr[i];
            pos = pos+2;
        }
        else
        {
            ans[neg] = arr[i];
            neg = neg+2;
        }
    } 
    //Print the array
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << " ";
    }

    //TC -> O(n) : Single iteration
    //SC -> O(n) : New arrays
}

void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void first_try(int arr[], int size)
{
    //2 pointer strategy, 1 pointer pointing to the wrongly placed element, 2nd one finding the correct element ahead and then swap them
    for (int i = 1; i < size; i++)
    {
        if (arr[i]*arr[i-1] > 0)
        {
            //find the first element ahead of it which is suitable for this place
            for (int j = i; j < size; j++)
            {
                if (arr[j]*arr[i] <0)
                {
                    swap(arr[i], arr[j]);
                    break;
                }
            }           
       }
    }
    //Print the array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    //TC -> O(n^2)
    //SC -> O(1) 
}

int main()
{
    //An array with N(even) elements is given, arrange the array with elements arranged with alternative signs with their relative order being the same.
    //Points -> Alternate the sign, preserve the relative order.
    int arr[] = {-3,1,2,5,-2,-4,7,-1};
    int size = sizeof(arr)/4;
    ////first_try(arr,size);
    optimal(arr,size);
}