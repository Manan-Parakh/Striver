#include<bits/stdc++.h>
using namespace std;

void first_try(int arr[], int size)
{
    //Fall back to the brute force approach of creating 2 sep vectors (size unknown)
    vector<int>pos;
    vector<int>neg;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >0)
        {
            pos.push_back(arr[i]);
        }
        else neg.push_back(arr[i]);
    }

    //the pattern of filling the answer array will be the same of min(pos,neg) number of elements
    for (int i = 0; i < min(pos.size(), neg.size()); i++)
    {
        arr[i*2] = pos[i];
        arr[i*2 + 1] = neg[i]; 
    }
    //fill the rest of the elements as it as
    for (int i = 2*min(pos.size(),neg.size());i<size; i++)
    {
        if (pos.size() > neg.size())
        {
            arr[i] = pos[i-min(pos.size(),neg.size())];
        }
        else arr[i] = neg[i-min(pos.size(),neg.size())];
    }
    //Print the array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    } 
    //TC -> O(n) + O(min(pos.size,neg.size)) + O(leftovers) 
    //   -> O(n) + O(n) //Worst case -> O(o)+O(n) 
    //SC -> O(n)
}


int main()
{
    //When number of pos and neg are not same
    //Add the excess of them at the end without altering order
    int arr[] = {1,2,-3,5,-2,4,6,-7};
    int size = sizeof(arr)/4;
    first_try(arr,size);
}