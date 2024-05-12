#include<bits/stdc++.h>
using namespace std;

// Remove Duplicates in_place from sorted arrays and return the number of unique elements.
// Place anything in the remaining, no one cares!
int first_try(int v[], int size)
{
    //A for loop
    int i = 0; // i will parse along the vector jumping across repeated elements
    for (int j = 0; j < size; j++)
    {
        if (v[j] != v[i])
        {
           v[++i] = v[j];
        }
    }
    
    // TC -> O(n)

    //printing the array
    for (int p = 0; p < size; p++)
    {
        cout << v[p] << ' ';
    }
    return i+1; //Number of unique elements
}

int brute(int v[], int size){
    // Word unique -> Sounds like set
    set<int> s;
    for (int i = 0; i < size; i++) //TC -> O(n*logn)
    {
        s.insert(v[i]);
    }
    
    // Set -> place elements into the array
    for (int i = 0; i < s.size(); i++) //TC -> O(N)
    {
        v[i] = *(s.begin()) + i;
    }
    
    // printing elements of set
    for (int p = 0; p < size; p++)
    {
        cout << v[p] << ' ';
    }
    return s.size();

    // TC -> O(n*logn): adding elements + O(n): for loop
    // Printing -> O(n)
    // SC -> Creating a set and then inserting elements -> O(n)
}

int main()
{
    int v[] = {1,1,2,2,2,3,4,4,4,5,6};
    int size = sizeof(v)/4;
    //cout << endl << first_try(v,size);
    cout << endl << brute(v,size);
}