#include <bits/stdc++.h>
using namespace std;
int INF = 2e9;
const int N = 1e5+1;
int n,k;
int h[N],dp[N];

int stone(int n){
    //base case
    if(n==1){
        return 0;
    }
    // if ans is already calculated
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = INF;
    for(int i=1;i<=k;i++){
        if(n-i <= 0){ // corner case
            break;
        }
        int candidate_ans = stone(n-i) + abs(h[n] - h[n-i]);
        ans = min(ans,candidate_ans);
    }
    dp[n] = ans;
    return ans;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    for(int i=1;i<=n;i++){
        dp[i] = -1;
    }

    cout<<stone(n)<<endl;

    return 0;
}
/**
dp series
https://atcoder.jp/contests/dp/tasks/dp_b
**/
