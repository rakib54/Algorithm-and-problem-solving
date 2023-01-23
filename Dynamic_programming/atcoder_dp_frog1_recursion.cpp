#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int h[N];
int dp[N];

int stone(int n){
    //1. base case
    if(n == 1) return 0;
    //2. check if answer already exists
    if(dp[n] != -1){
        return dp[n];
    }
    //3. calculate answer from subproblems
    int ans1 = stone(n-1) + abs(h[n] - h[n-1]);

    // corner case
    if(n==2){
        dp[n] = ans1;
        return dp[n];
    }
    int ans2 = stone(n-2) + abs(h[n] - h[n-2]);
    int ans = min(ans1,ans2);
    dp[n] = ans;
    return ans;
}

int main (){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    for(int i=1;i<=n;i++){
        dp[i] = -1;
    }

    cout<<stone(n)<<endl;

    return 0;
}

/*
https://atcoder.jp/contests/dp/tasks/dp_a
4
10 30 40 20

2
10 10

6
30 10 60 10 60 50

*/

