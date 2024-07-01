#include <bits/stdc++.h>
using namespace std;

//An idea that did not work. Nonetheless let's preserve the logic
//This Idea will work, just implement a checking step at the end -> An Idea that popped while driving
vector<int> first_try(vector<int>& vec)
{
    vector<int> ans;
    // Create the variables to store 2 distinct digits along wit their counters
    int val1 = -1, val2 = -1;
    float cnt1 = 0, cnt2 = 0;

    for (auto ele : vec)
    {
        if (val1 == -1 || cnt1 == 0 || val1 == ele)
        {
            val1 = ele;
            cnt1++;
            cnt2 = cnt2 - 0.5;
        }
        else if (val2 == -1 || cnt2 == 0 || val2 == ele)
        {
            val2 = ele;
            cnt2++;
            cnt1 = cnt1 - 0.5;
        }
        else
        {
            cnt1 = cnt1 - 0.5;
            cnt2 = cnt2 - 0.5;
        }
    }

    if (cnt1 > 0)
    {
        ans.push_back(val1);
    }
    if (cnt2 > 0)
    {
        ans.push_back(val2);
    }
    return ans; 
}

vector<int> 
int main()
{
    vector<int> vec = {1, 1, 3,1, 3, 2, 2, 2};
    for (auto ele : first_try(vec))
    {
        cout << ele << " ";
    }
}