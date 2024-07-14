#include<bit/stdc++.h>
using namespace std;

int check(vector<int>& stalls, int C, int dist)
{
    //Goal of this fxn is to check if with the given indices, is it possible to achieve the given dist or not
    //We want C posns in total, 2 of them being 0 and last
    //The min will always happen between consecutive cows
    int cnt = 0;
    for (int i = 0; i < stals.size()-1; i++)
    {
        if (stalls[i+1] - stalls[i] >= dist)
        {
            cnt++;
        }
    }cout << cnt;
    if (cnt >= C)
    {
        return 1;
    }
    else return 0;
}

int AggrCows(vector<int>& stalls, int C)
{
    int N = stalls.size();
    cout << N;
    sort(stalls.begin(),stalls.end());
    int min_dist_low = 1, min_dist_high = stalls[N-1] - stalls[0];
    while(min_dist_low <= min_dist_high)
    {
        int min_dist_mid = (min_dist_low + min_dist_high)/2;
        //Check if it is mathematically possible or not
        if (stalls[N-1] - stalls[0] < min_dist_mid*(C-1))
        {
            //Reduce the min_dist
            min_dist_high = min_dist_mid-1;
            continue;
        }
        //If possible, our goal is to find the C-2 indices as we will place 2 cows at the extremeties
        //Check if possible
        int flag = check(stalls,C,min_dist_mid);
        if (flag == 1)
        {
            //Probable answer, try to find a bigger value now
            ans = min_dist_mid;
            low = min_dist_mid +1;
        }
        else high = min_dist_mid-1;
    }
    return ans;
}
int main()
{
    vector<int> stalls = {1,2,8,4,9};
    int cows = 3;
    cout << AggrCows(stalls,cows);
}