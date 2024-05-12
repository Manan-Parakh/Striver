#include<bits/stdc++.h>
using namespace std;

void swap(int* p, int*q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
    return;
}
int main()
{
    //Implementing Selection Sort
    int arr[] = {13,46,24,52,20,9};

    for (int i = 0; i < sizeof(arr)/4; i++)
    {
        for (int j = i; j < sizeof(arr)/4; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j],arr[i]);
            }
        }
    }
    
    for (auto it: arr )
    {
        cout << it << " ";
    }
    
}