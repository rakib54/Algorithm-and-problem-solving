#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long solve(int i,vector<long long>&dp, vector<vector<int>>& questions){
    if(i >= questions.size()){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    long long pick = questions[i][0] + solve(i + questions[i][1] + 1, dp, questions);
    long long not_pick = 0 + solve(i+1, dp, questions);

    return dp[i] = max(pick, not_pick);
}

void solve(){
  vector<vector<int>> questions {{3,2}, {4,3},{4,4},{2,5}};
  int n = questions.size();
  if(n == 1){
      cout<<questions[0][0];
      return;
  }
  vector<long long>dp(n, -1);
  cout<< solve(0,dp,questions);

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
