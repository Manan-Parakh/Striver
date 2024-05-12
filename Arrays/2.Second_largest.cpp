#include<bits/stdc++.h>
using namespace std;

void first_try(int v[], int size){
    int high = v[0]; //Stores the max value
    int low = v[0]; //Stores the 2nd max value

    for (int i = 0; i < size; i++)
    {
        // If the element present is greater than high, i.e highest till now; current high becomes the new low
        if (v[i] > high)
        {
            low = high;
            high = v[i];
        }
        else if (v[i] > low)
        {
            low = v[i];
        }
    }
    cout << low;
    
    // TC -> O(n);
    // SC -> O(1) as only 2 var are created additionally
}

void brute(int v[], int size){
    //When using brute force, don't simply return v[n-2] (of the sorted array) as the 2nd largest, it might be the case that lar element has frequency greater than 1. So Run a for loop to find the 2nd lar in the sorted array
    // Brute : TC -> O(n*log(n)) + O(n) 
    // Sort + For loop
    // SC -> O(1) // as no additional variable is created
}

void better(int v[], int size){
    // 2 For loops -> Largest and then second largest
    int largest = v[0];
    int s_largest = INT_MIN; //If negatives are also there
    
    //Finding the largest
    for (int i = 0; i < size; i++)
    {
        if (v[i] > largest)
        {
            largest = v[i];
        }
    }
    // Finding the s_largest
    for (int i = 0; i < size; i++)
    {
        if (v[i] > s_largest && v[i] < largest)
        {
            s_largest = v[i];
        }
    }
    cout << s_largest;

    // TC -> O(n) but 2 for loops
    // SC -> O(1)
}

int main()
{
    int v[] = {1,5,4,3,2,6,7,9};
    // first_try(v, sizeof(v)/4);
    better(v, sizeof(v)/4); 
}