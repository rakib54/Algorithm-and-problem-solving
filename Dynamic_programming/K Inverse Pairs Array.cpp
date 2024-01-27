#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][1001];

    int solve(int n, int k){
        
        if(n == 0){
            return 0;
        }
        if(k == 0){
            return 1;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        int result = 0;
        for(int inv = 0; inv <= min(k, n-1); inv++){
            result = (result % mod + solve(n-1, k -inv) % mod) % mod;
        }

        return dp[n][k] = result;
    }
    
    int kInversePairs(int n, int k) {
        memset(dp, -1,sizeof(dp));
        return solve(n, k);
    }
};

int main(){
  Solution s;

  s.kInversePairs(5,2);
  
  return 0;
}
