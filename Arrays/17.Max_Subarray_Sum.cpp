#include<bits/stdc++.h>
using namespace std;

void brute_better()
{
    /*
    Parse through the entire array and find the sum of all the subarrays
    */
   //Brute -> O(n3)
   //Better ->O(n2) by simply removing the inner most loop the calculates the sum of the subarray.
}

void optimal_kadane(int arr[], int size)
{
    // Intuition: We do not carry forward negative sum
    int maxi = INT_MIN; //stores the maximum sum encountered
    int sum = 0; //stores the current sum
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
        maxi = max(maxi,sum);
        if (sum < 0)    
        {
           sum = 0;
        }
    }
    cout << "Maximum Sum: " << maxi;
}

int main()
{
    //Find the SubArray with max sum
    int arr[] = {-2,-3,4,-1,-2,1,5,-4};
    int size = sizeof(arr)/4;
    optimal_kadane(arr,size);
}