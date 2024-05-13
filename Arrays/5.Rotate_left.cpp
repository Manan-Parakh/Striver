#include<bits/stdc++.h>
using namespace std;

void first_try(int arr[], int size)
{
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

int main()
{
    // Left rotate an array by one place; inplace
    // [1,2,3] -> [2,3,1]
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/4;
    first_try(arr,size);

    // Print the array
    for (auto it : arr)
    {
        cout << it << ' ';
    }
    
}
