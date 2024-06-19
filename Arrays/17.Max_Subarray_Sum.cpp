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

// To get the max sum 
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
// To get the subarray with max sum as well
void optimal_kadane_2(int arr[], int size)
{
    int maxi = INT_MIN; //stores the maximum sum encountered
    int sum = 0; //stores the current sum

    // We will carry the starting and ending index of the subarray with maximum sum
    int low = 0, high = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
        if(sum > maxi)
        {
            maxi = sum;
            high = i;
        }
        if (sum < 0)   
        {
           sum = 0;
           low = i+1;
           high = i+1;
        }
    }
    cout << "Maximum Sum: " << maxi << endl;
    for(int i = low; i<= high; i++)
    {
        cout<< arr[i] << endl;
    }
}

int main()
{
    //Find the SubArray with max sum
    int arr[] = {-2,-3,4,-1,-2,1,5,-4};
    int size = sizeof(arr)/4;
    ////optimal_kadane(arr,size);
    optimal_kadane_2(arr,size);
}