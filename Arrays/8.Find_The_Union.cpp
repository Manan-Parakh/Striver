#include<bits/stdc++.h>
using namespace std;

void optimal(int arr1[], int s1,int arr2[], int s2)
{
    // 2 pointer approach; use index -> pointer
    int a1 = 0, a2 = 0;
    vector<int> u;
    // The union contains <unique> and <sorted> elements
    while (a1 < s1 && a2 < s2) // TC-> O(min(n,m))....WorstCase: O(n) when n==m; 
    //n = size(arr1), m = size(arr2)
    {
        cout << a1 << a2 << endl;
        if ((arr1[a1] <= arr2[a2]))
        {
            if (u.empty())
            {
                u.push_back(arr1[a1]);
            }
            else if (u.back() != arr1[a1])
            {
                u.push_back(arr1[a1]);
            }
            a1++;   
        }
        else if ((arr2[a2] <= arr1[a1]))
        {
           if (u.empty())
            {
                u.push_back(arr2[a2]);
            }
            else if (u.back() != arr2[a2])
            {
                u.push_back(arr2[a2]);
            }
            a2++;
        }
    }
    while(a1<s1) // TC -> O(n-m) //worst case -> O(n) when the other set is empty
    {
        cout << a1 << endl;
        if (u.back() != arr1[a1])
        {
            u.push_back(arr1[a1]);   
        }
        a1++;
    }
    while(a2<s2) // TC -> O(m-n) //worst case -> O(m)
    {
        cout << a2 << endl;
        if (u.back() != arr2[a2])
        {
            u.push_back(arr2[a2]);   
        }
        a2++;
    }

    //Print the union
    for (auto it : u)
    {
        cout << it << ' ';
    }
    
    //TC -> O(min(n,m)) + O(mod(m-n)) // Worst Case -> O(m+n) overall 
    // Because no matter what we do, we are in one way or another iterating through all the elements of arr1 and arr2.
    //SC -> O(m+n) //worst case -> All the elements are different
    // The space is being used to return the answer, not in the Algorithm.
}

int main()
{
    //Union of 2 <sorted> arrays!
    int arr1[] = {1,1,2,3,4,5};
    int arr2[] = {2,3,4,4,5,6};
    int s1 = sizeof(arr1)/4;
    int s2 = sizeof(arr2)/4; 
    optimal(arr1,s1,arr2,s2);
}