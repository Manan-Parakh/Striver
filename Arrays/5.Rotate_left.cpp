#include<bits/stdc++.h>
using namespace std;

void first_try(int arr[], int size)
{
    cout << "1st try was called!" << endl;
    // Store arr[0] in temp and then move all elements to the left placing temp in the end
    int temp = arr[0];
    for (int i = 1; i < size; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[size-1] = temp;

    // TC -> O(n)
    // SC -> O(1) -> Extra Space
    // Space used to solve the problem: O(n), as we are using the array, though already given, to solve the problem
    // How to optimize it further?
}

void first_try_D(int arr[], int size, int d)
{
    if (!(d%size))
    {
        cout << "Same Array!" << endl;
        return;
    }
    d = d%size;
    // Time Efficient Approach
    // store the 1st d elements into a new array
    int temp[d] ={0};

    //shift the elements in the array
    for (int i = 0; i < size; i++)
    {
        if (i<d)
        {
            temp[i] = arr[i];
        }
        if (i < size-d)
            arr[i] = arr[i+d];
        else
            arr[i] = temp[i-size+d];
    }
    
    // Initially I used 3 for loops for the 3 diff tasks. 
    // Combined them! Good Optimization ig...
    //TC -> O(n)
    //SC -> O(n)
    //max size of possible array: n-1, as we will not trigger the fxn if the rotn is going to lead to the same array.
}

void brute_D(int arr[], int size, int d)
{
    if (!(d%size))
    {
        cout << "Same Array!" << endl;
        return;
    }
    d = d%size;
    // call first_try D times;
    for (int i = 0; i < d; i++)
    {
        first_try(arr,size);
    }
}

void swap(int* p, int*q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void optimal_D(int arr[], int size, int d)
{
    if (!(d%size))
    {
        cout << "Same Array!";
        return;
    }
    // This method optimizes the space complexity further

    //Approach: We rotate the first d elements in their place and next size-d el in their place
    //Rotate the whole array
    //rev -> use swapping
    d = d%size;
    //reverse 1
    for (int i = 0; i < d/2; i++) //TC -> O(d/2)
    {
        swap(arr[i], arr[d-i-1]);
    }
    for (int i = d; i < (d+size)/2 ; i++) //TC -> O((size-d)/2)
    {

        swap(arr[i], arr[size-1-i+d]);
    }
    // Swap the complete array // TC-> O(size/2)
    for (int i = 0; i < size/2; i++)
    {
        swap(arr[i],arr[size-1-i]);
    }

    //TC -> O(2n)
    //SC -> O(1)
    
}

int main()
{
    // Left rotate an array by one place; inplace
    // [1,2,3] -> [2,3,1]

    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/4;
////first_try(arr,size);

    // For rotn by D places, every rotn by value = size, leads to the same array. So we use D%size to save time and space
    int D;
    cin >> D;

////first_try_D(arr, size, D);
////brute_D(arr,size,D);
    optimal_D(arr,size,D);
    
    // Print the array
    for (auto it : arr)
    {
        cout << it << ' ';
    }
    
}
