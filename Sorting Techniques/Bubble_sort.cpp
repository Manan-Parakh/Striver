#include<bits/stdc++.h>
using namespace std;

void swap(int* p, int* q )
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
int main()
{
    // Basic Implementation
    // Pushes the largest element to the end using ADJACENT SWAPS
    
    //int arr[] = {13,46,24,53,20,9}; //TC -> O(N**2)
    int arr[] = {1,2,3,4,5,6}; // TC -> O(N)
    
    // i takes care of the position where the current max element is to be stored 
    for (int i = sizeof(arr)/4-1; i >=1; i--)
    {
        int didSwap = 0;
        // j points to the beginning of the pair to be checked
        for (int j = 0; j < i ; j++)
        {
            // TO Optimize
           
            if (arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                didSwap = 1;
            }
            
        }
        if (didSwap == 0)
        {
            break;
        }
        cout << "runs" << endl;        
    }

    // Printing the Array
    for (auto it : arr)
    {
        cout << it << " ";
    }
    
    
    
}