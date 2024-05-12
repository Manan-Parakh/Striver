#include<bits/stdc++.h>
using namespace std;

void swap(int* p, int* q )
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void try1()
{
    int arr[] = {14,9,15,12,6,8,13};

    for (int i = 0; i < sizeof(arr)/4; i++)
    {
        int j = i;
        while (arr[j] < arr[j-1] && j>0)
        {
            swap(arr[j],arr[j-1]);
            j--;       
        }
    }
    
    for (auto it : arr)
    {
        cout << it << " ";
    }
     
}
int main()
{
    int arr[] = {14,9,15,12,6,8,13};
    try1();
}