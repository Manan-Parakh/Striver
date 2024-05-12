#include<bits/stdc++.h>
using namespace std;

void print_n(int a, int n)
{
    //Print Linearly from N to 1
    // fxn call: print_n(n,n)
    if (a < 1)
    {
        return;
    }
    cout << a << endl;
    print_n(a-1,n);
}

void print_n_back(int a, int n){
    //By backtracking
    //fxn call: print_n_back(1,n);
    if (a > n)
    {
        return;
    }
    print_n_back(a+1,n);
    cout << a << endl;
}

int sum_first_n_fxnl_way(int n){
    if (n == 0)
    {
        return 0;
    }
    return (n + sum_first_n_fxnl_way(n-1));
}

void sum_first_n_parameterised_way(int i, int sum){
    if (i < 1)
    {
        cout << sum;
        return;
    }
    sum_first_n_parameterised_way(i-1,sum+i);
}

int factorial_fxnl_way(int n){
    if (n == 1)
    {
        return 1;
    }
    return n*factorial_fxnl_way(n-1);   
}

void factorial_parameterised_way(int i, int fact){
    if (i < 1)
    {
        cout << fact;
        return;
    }
    factorial_parameterised_way(i-1, fact*i);
}

void arr_rev(int arr[],int size, int i){
    if (i >= size/2)
    {
        return;        
    };
    // swap the arr[i] and arr[size-i] elements
    int temp = *(arr+i);
    *(arr+i) = *(arr+size-i-1);
    *(arr+size-i-1) = temp;
    arr_rev(arr, size, i+1);
}

int str_plndrm(string s, int i)
{
    /* Fxn Call ->
    if (str_plndrm(s,0))
    {
        cout << "It is a Palindrome";
    }
    else cout << "No it is not a Palindrome";
    */
    if (i >= s.size()/2)
    {
        return 0;
    }
    if (s[i] == s[s.size()-1-i])
    {
        return 1 + str_plndrm(s,i+1);
    }
    else return 0 + str_plndrm(s,i+1);
}

int fibonacci(int n)
{
    // fxn call -> Fibonacci(n);
    // i -> index
    // n-> number of terms we want. 0 being the 0th term
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n);
}