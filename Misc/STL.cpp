#include<bits/stdc++.h>
using namespace std;

void expPairs()
{
    //pair<int,int> p1 = {1,3};
    //cout << p1.first;
    //cout << p1.second;
    
    //pair<int, pair<int,int>> p2;
    //p2 = {5, {10,15}};
    //cout << p2.first << endl;
    //cout << p2.second.first << endl;
    //cout << p2.second.second << endl;

    // Pair is a simple container that can hold 2 values.

    pair<int,int> arr[] = {{1,2},{3,4}};
    cout << arr[1].first;
}

void expVectors()
{
    // Arrays are fixed in size, Vectors are dynamic in nature.
    // Vector stores data, it is not a datatype
    // vector<datatype> name;
    
    //vector<int> v;
    //v.push_back(1);
    //v.emplace_back(2);
    //cout << *(v.begin()+1);

    /* vector<pair<int,int>> v2;
    v2.push_back({1,2});
    v2.emplace_back(3,4);
    cout << v2[1].first; */

    //vector<int> v3(5,100); // vector with 5 elements, all at value 100
    //vector<int> v4(5); //vector with 5 elements, all 0 or garbage values

    //Creating a copy of a vector
    //vector<int> v5(5,20);
    //vector<int> v5_copy(v5);

    //Iterators
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    v.emplace_back(3);
    v.emplace_back(4);
    v.emplace_back(5);
    
    //vector<int>::iterator or auto
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << endl;
    }

    // A colon and it stores the value.
    //auto or int here
    for (auto it : v)
    {
        cout << it << endl;
    }
}

bool comp(pair<int,int>p1, pair<int,int>p2){
    if (p1.second < p2.second)
    {
        return true;
    }
    else if (p1.first > p2.first)
    {
        return true;
    }
    return false;
}

void custom_comparator()
{
    pair<int,int> a[] = {{1,2}, {2,1},{4,1}};
    /*
    Sort it in the ascending order of second elements, if second elements are same,
    sort in descending order of first elements*/
    sort(a,a+3,comp);
    for (auto i : a)
    {
        cout << i.first << i.second << ' ';
    }
    
}

void pop_count()
{
    // Counts 1 in the Binary Representation of a Number
    int num = 7;
    int cnt = __builtin_popcount(num);
    //For long long int -> __builtin_popcount(num)
    cout << cnt;
}

void next_perm()
{
    string s = "abcde";

    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(),s.end()));
    // next_permutation returns null after the last possible permutation
}

void maxi(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    v.push_back(4);
    
    //max_element returns the iterator to the maximum valued element.
    int maxi = *max_element(v.begin(),v.end());
    cout << maxi;
}

int main()
{
    maxi();
}