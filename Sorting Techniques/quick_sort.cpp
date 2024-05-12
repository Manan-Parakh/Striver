#include<bits/stdc++.h>
using namespace std;

void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void quicksort(vector<int> &v, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    // Fix a pivot and keep it at its correct posn.
    // Let us fix pivot to be the first element
    int pivot = v[low];
    int i = low +1;
    int j = high;
    while (true)
    {
        // Do the swap thing
        while (i <= j && v[i] <= pivot) i++;
        while (j >= i && v[j] > pivot) j--;
        if (i >= j) break;
        swap(v[i++],v[j--]);
    }
    swap(v[low],v[j]);

    // Now j: partition index
    // 2 arrays: low-> partiton-1 and partition+1 -> high
    quicksort(v, low, j-1);
    quicksort(v,j+1,high);
}
int main()
{
    vector<int> v = {4,6,2,5,7,9,1,3};
    quicksort(v, 0, v.size()-1);

    for (auto it : v)
    {
        cout << it << ' ';
    }
    
}