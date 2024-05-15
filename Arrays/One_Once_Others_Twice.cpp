#include<bits/stdc++.h>
using namespace std;

void optimal(int arr[], int size)
{
    int x = 0;
    for (int i = 0; i < size; i++)
    {
        x = x^arr[i];
    }
    cout << x;
}

void hashing()
{
    //For loop -> TO find the biggest element in the array, so that we can define hash array
    //For loop -> Hash the values
    //For loop -> Find the hash value with frequency 1

    //TC -> O(3n)
    //SC -> O(max_element(arr))
}

int main()
{
    //give an array, find the element that occurs only once while others occur twice
    //Similar to finding the missing number in the array, the xor concept
    // Xor of similar numbers = 0 and Xor of 0 and a number = the number itself
    int arr[] = {1,1,2,3,3,4,4};
    int size = sizeof(arr)/4;
    optimal(arr,size);
}