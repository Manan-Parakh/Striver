#include<bits/stdc++.h>
using namespace std;

void first_try(int arr[], int N)
{
    //size of array = N-1
    int sum = (N*(N+1))/2;
    //sum of the el of array
    for (int i = 0; i < N-1; i++)
    {
        sum = sum - arr[i];
    }
    cout << "Missing Number is: " << sum;
    
    //TC -> O(n)
    //SC -> O(1)
}

void brute_better()
{
    /*Brute
    Run 2 for loops
    TC -> O(n^2)
    SC -> O(1)
    */

   /*Better
   Use Hashing to get all the elements
   Use Hash Array of size N+1 -> TO get index upto N
   for loop -> Fill the Hash array
   for loop -> Find the index with value 0 in Hash Array

   TC -> O(n+n)
   SC -> O(n)
   */
}

void optimal2(int arr[], int N)
{
    //Using XOR
    // Will come back later to it after learning Bit Manipulation
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < N-1; i++)
    {
        xor1 = xor1^(i+1);
        xor2 = xor2^arr[i];
    }
    xor1 = xor1^N;
    int num = xor1^xor2;
    cout << "Missing Number is: " << num;
}

int main()
{
    //A number N will be given and an array of size N-1 containing num from 1 to N with 1 missing
    //Find the missing number
    int N = 6;
    int arr[] = {1,2,3,4,6};
////first_try(arr,N);
    optimal2(arr,N);
}