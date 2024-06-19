#include<bits/stdc++.h>
using namespace std;

void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void first_try(int arr[], int size)
{
    //2 pointer strategy, 1 pointer pointing to the wrongly placed element, 2nd one finding the correct element ahead and then swap them
    int flag; //multiplication with flag must be positive for an element to be declared correctly placed
    if (arr[0] > 0)
    {
        flag = -1;
    }
    else flag = 1;
    
    for (int i = 1; i < size; i++)
    {
        if (arr[i]*flag < 0)
        {
            //find the first element ahead of it which is suitable for this place
            for (int j = i; j < size; j++)
            {
                if (arr[j]*flag >0)
                {
                    swap(arr[i], arr[j]);
                    break;
                }
            }           
       }
       flag = flag*-1;
    }

    //Print the array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    
    
}
int main()
{
    //An array with N(even) elements is given, arrange the array with elements arranged with alternative signs with their relative order being the same.
    //Points -> Alternate the sign, preserve the relative order.
    int arr[] = {-3,1,2,-5,2,-4,7,9,-1,-4};
    int size = sizeof(arr)/4;
    first_try(arr,size);
}