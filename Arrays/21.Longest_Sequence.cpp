#include<bits/stdc++.h>
using namespace std;

void ideas_that_pop_in_the_mind()
{
    /*
    1. Hashmap
    2. Parse through the array, assume each element to be the starting of a sequence. TC-> O(N^N) as for each element we will have to run a loop N times
    */
}
//An Idea Half Finished
void relation_matrix(int arr[], int size)
{
    //Get the relation matrix
    int rel_mat[size][size] = {0};
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            rel_mat[row][col] = arr[row] - arr[col];
        }
    }
    //For Each element, check if -1 exists in its row, if yes, then check for this again in the row of the column element
    int len = 0;
    for (int i = 0; i < size; i++)
    {
        int row_check = i;
        while (1)
        {
            //Check for -1 in the row i
            for (int j = 0; j <= size; j++)
            {
                if (rel_mat[row_check][j] == -1)
                {
                    len++;
                    row_check = j;
                }
            }
        }
        
    }
    
}

//The internal loop's TC will be additive not multiplicative
//Therefore, N^N is wrong, rather N^3 as N*(N*N for internal loop)
void brute()
{
    /*
    parse thorugh the array assuming each element to be the starting point, then check if next el of its seq is there or not... and carry on until the next is not there.
    Keep counter and longest -> 2 ints to store current length and max length

    //TC -> O(N^3) as for each element chosen, we will have to parse thorugh the complete array (at worst) to check for the next one... and the max possible length of sequence is N.
    //SC -> O(1)
    */
   /*
    We can improve the brute one by first hashing all the elements so that while checking for sequence of a selected element, we do not have to parse through the complete array again and again.
    
    1. Create a Hashmap:TC -> O(N*Log(N)) if Ordered Map
                        TC -> O(N*1) if Unordered Map and O(N*N) if collisions
                        SC -> O(N)
    2. Parse thorugh the array and check for sequence for each element
        TC -> O(N^2)
    */
}

void better(int arr[], int size)
{
    //Idea: Sort (N*Log(N)) and then check for the longest subsequence
    //Keep a track of currentlen, maxlen and last_smallest
    //For an element to be a part of the sequence, it must be +1 of last_smallest,
    //if not, treat it as a new beginning

    //Sort the array
    sort(arr, arr+size);

    //find the longest sequence
    int cnt = 1; //Keeps track of current len of seq
    int max_len = 1;
    int ls = INT_MIN; //Last-Smallest

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ls+1)
        {
            ls = arr[i];
            cnt++;
            max_len = max(cnt,max_len);
        }
        else if (arr[i] != ls+1)
        {
            ls = arr[i];
            cnt = 1;
        }
    }
    cout <<"Max:" <<  max_len;

    //TC -> O(N*Log(N)) + O(N)
    //SC -> O(1)
}

void optimal(int arr[], int size)
{
    //We distorted the given array in the better approach, so we now try to do it without it.
    //Store all the elements in an unordered set
    //Similar to Brute, its just that we do not check for sequence for elements that are not the starting point of any probable sequence, i.e if for an element, el-1 exists, we abandon it.
    //We check for seq only from probable starting points

    //Store all the elements in an u_set
    unordered_set<int> st;
    for (int i = 0; i < size; i++)
    {
        st.insert(arr[i]);
    }
    
    int cnt = 1;
    int max_len = 1;
    //Iterate in the set
    for (auto it : st)
    {
        if (st.find(it-1) == st.end())
        {
            cnt = 1;
            int x = it;
            while (st.find(x+1) != st.end())
            {
                cnt++;
                x++;
            }
            max_len = max(cnt,max_len);
        }   
    }
    cout <<max_len;

    //Unordered Set: best/avg case -> O(1), worst -> O(N): collisions
    //TC -> O(n*1) for storing elements in the set + O(2n) bcz we do not loop over all the elements for sequence, we utilized the internal loop only when the chosen element is a probable starting point.

    //SC -> O(N)
}

int main()
{
    int arr[] = {1,1,6,8,2,3,4,5};
    int size = sizeof(arr)/4;
    optimal(arr,size);
}