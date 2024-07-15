#include <bits/stdc++.h>
using namespace std;

void subseq(vector<int> &arr, vector<int> &empty, int index)
{
    // For the given index, we can have 2 options, either print it or not
    // Bcz we want it in order, we will print it while going ahead
    if (index >= arr.size())
    {
        // Print the empty array
        for (auto it : empty)
        {
            cout << it;
        }
        cout << endl;
        return;
    }
    empty.push_back(arr[index]);
    subseq(arr, empty, index + 1);
    empty.pop_back();
    subseq(arr, empty, index + 1);

    //TC -> 2^n * n (For printing)
    //SC -> O(n)
    //Stack Space -> O(n) as the max number of recursion calls at once:n
}
int main()
{
    vector<int> arr = {3, 1, 2};
    // 2^n subseqs
    vector<int> empty = {};
    subseq(arr, empty, 0);
}