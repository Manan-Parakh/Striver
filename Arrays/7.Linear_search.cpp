#include<bits/stdc++.h>
using namespace std;

int lin_search(int arr[], int size, int num){
    for(int i = 0; i<size; i++){
        if(arr[i] == num) return i;
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/4;
    int num = 6;
    cout << lin_search(arr,size,num);
}