#include <bits/stdc++.h>
using namespace std;

int arr[101];

int fibo(int n){
    if(n <= 2) return 1;
    // check if fib(n) is already calculated
    if(arr[n]){ // if value is non zero
        return arr[n];
    }
    arr[n] = fibo(n-2) + fibo(n-1);
    return arr[n];
}

int main (){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cout<<fibo(i)<<" ";
    }
    return 0;
}

