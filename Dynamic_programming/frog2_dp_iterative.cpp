#include <bits/stdc++.h>
using namespace std;
int INF = 2e9;
const int N = 1e5+1;

int h[N],dp[N];

int main(){
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    dp[1] = 0; // base case

    for(int i=2;i<=n;i++){
        dp[i] = INF;
        for(int j=1;j<=k;j++){
            if(i-j <=0) break; //corner case
            int candidate_ans = dp[i-j] + abs(h[i] - h[i-j]);
            dp[i] = min(dp[i], candidate_ans);
        }
    }

    cout<<dp[n];
}

/**
dp series
https://atcoder.jp/contests/dp/tasks/dp_b
**/
