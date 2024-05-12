#include<bits/stdc++.h>
using namespace std;

void first_try(int v[], int size)
{
    // Just a for loop
    int flag = 0;
    for (int i = 0; i < size-1; i++)
    {
        if (v[i] >v[i+1]) //Don't use '=' here, as repeat elements are still sorted!
        {
            flag++;
            cout << "Unsorted array";
            break; // Break at the first instance as we simply need to tell if its sorted or not.
        }
    }
    if (!flag)
    {
        cout << "Sorted! ><";
    }
    // TC -> O(n), Can it be improved? Lemme think.
    // Oh yes, we can remove the need of the variable flag by simply returning True/ False. Better Space Complexity. void -> bool fxn.
}

int main()
{
    int v[] = {1,1,2,3,4,5};
    int size = sizeof(v)/4;
    first_try(v,size);
}