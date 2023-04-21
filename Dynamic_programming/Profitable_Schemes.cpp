#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N;
int dp[101][101][101];
int mod = 1e9 + 7;

int no_of_schemas(int i, int p, int people,int &minProfit, vector<int>& group, vector<int>& profit){
    if(people > N){
        return 0;
    }
    if(i == group.size()){
        if(p >= minProfit){
            return 1;
        }
        return 0;
    }

    if(dp[i][p][people] != -1){
        return dp[i][p][people];
    }
    long long not_taken = no_of_schemas(i+1,p,people,minProfit,group,profit) % mod;
    long long taken = no_of_schemas(i+1,min(p+profit[i], minProfit),people + group[i],minProfit,group,profit) % mod;

    return dp[i][p][people] =  (taken + not_taken) % mod;
}

void solve(){
  int n = 5;
  int minProfit = 3;
  vector<int> group{2,2};
  vector<int>profit{2,3};
  N = n;
  memset(dp,-1,sizeof(dp));
  
  cout<< no_of_schemas(0,0,0,minProfit,group,profit);

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
