#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int dp[100001];

int solve_dp(int i,int low, int high, int zero, int one){
    if(i > high){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    bool add_one = false;
    if(i >= low  && i<=high){
        add_one = true; // if add_one = true -> +1 otherwise +0
    }
    int append_one = solve_dp(i+one, low, high,zero, one);
    int append_zero = solve_dp(i+zero, low, high,zero, one);

    
    return dp[i] = (add_one + append_one + append_zero)%mod;
}

void solve(){
  int low = 3, high = 3, zero = 1, one = 1;
  memset(dp, -1, sizeof(dp));
  cout<<solve_dp(0,low,high,zero,one);

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
