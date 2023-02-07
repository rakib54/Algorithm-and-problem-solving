#include <bits/stdc++.h>
using namespace std;
const int N = 3001;
int dp[N][N];
string s,t;
int n,m;

int LCS(int i, int j){
  // 1. base case
  if(i == n || j == m){
    return 0;
  }
  if(dp[i][j] != -1){
    return dp[i][j];
  }

  // calculate ans from smaller subproblems
  if(s[i] == t[j]){
    int ans = 1 + LCS(i+1, j+1);
    dp[i][j] = ans;
    return ans;
  }
  int ans = max(LCS(i+1, j),LCS(i, j+1));
  dp[i][j] = ans;
  return ans;

}

int main(){
  cin>>s>>t;
  n = s.size();
  m = t.size();

  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      dp[i][j] = -1;
    }
  }

  cout<<LCS(0,0)<<endl;

  return 0;
}

/*
axyb
abyxb

-> ayb -> 3

abc
bca

-> bc -> 2
*/
