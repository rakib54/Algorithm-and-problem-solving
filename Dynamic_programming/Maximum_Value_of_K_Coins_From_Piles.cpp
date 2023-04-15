#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[1001][2001];

int find_max_value(int i,int n, vector<vector<int>>& piles, int k){
  if(i >= n) return 0;
  if(dp[i][k] != -1){
      return dp[i][k];
  }
  int notTaken = find_max_value(i+1,n,piles,k);
  int taken = 0;
  int sum = 0;
  int sz = piles[i].size();
  int minsize = min(sz,k); 

  for(int j = 0;j<minsize; j++){
      sum += piles[i][j];
      if(k - (j+1) >=0) {
          taken = max(taken, sum + find_max_value(i+1, n, piles, k-(j+1)));
      } 
  }
  return dp[i][k] = max(taken,notTaken);
}

void solve(){
  vector<vector<int>> piles{{1,100,3}, {7,8,9}};
  int k = 2;
  int n  = piles.size();
  memset(dp,-1, sizeof(dp));
  cout<< find_max_value(0,n,piles,k);

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
