#include<bits/stdc++.h>
using namespace std;

void brute()
{
    // Just writing the approach, no need of code
    /*
    we can loop over the first array and for each term try to check if arr2 also contains it. If yes
    we add it to intersection array.
    No need of looping similarly over the second array as the common terms are in both
    */
   /*
   We can optimize it by not looping over entire 2nd array to check the existense of concerned element of array 1. We can stop when the element in 2nd array becomed greater than concerned el of arr1.
   Still not optimal but a bit optimised ig.
   */
}
void first_try(int arr1[], int s1, int arr2[], int s2)
{
    //We will first find the smaller array ->To Optimize the loop... Implement this in the main itself
    //Assuming arr1 to be the smaller one, if the size of the two differ
    int a1 =0, a2 =0;
    vector<int> Inter;
    while (a1 < s1 && a2 < s2)
    {
        cout << a1  << a2 << endl;
        if ((arr1[a1] == arr2[a2]))
        {
            if(Inter.empty() || Inter.back() != arr1[a1])
            {
                Inter.push_back(arr1[a1]);
            }
            a1++;
            a2++;
        }
        else if (arr2[a2] > arr1[a1])
        {
            a1++;
        }
        else if(arr2[a2] < arr1[a1]) a2++;
    }

    //Print the Inter Array
    if(Inter.empty() == true)
    {
        cout << "No element is Common!";
        return;
    }

    for (auto it : Inter)
    {
        cout << it << ' ';
    }
    
    //TC -> O(m*n) //Worst case ->  No element is common and all the elements of arr1(smaller array) is larger than the largest element of arr2, so it parses through arr2 for size(arr1) number of times 
    //SC -> O(min(m,n)) //Worst case -> one array is subset of the other, just to return the answer
    
}

int main()
{
    // Intersection of two <sorted> arrays
    int arr1[] = {1,2,3,4,5,6,8};
    int arr2[] = {2,3,4,5,6,8,9};
    int s1 = sizeof(arr1)/4;
    int s2 = sizeof(arr2)/4;
    //Pass the smaller array as a1, to optimize time
    if (s1 < s2)
    {
        first_try(arr1,s1,arr2,s2);
    }
    else first_try(arr2,s2,arr1,s1);
    
}