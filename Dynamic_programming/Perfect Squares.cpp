#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int solve(int n, int dp[]){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int minCount = INT_MAX;

        for(int i = 1; i*i <= n; i++){
            int result = 1 + solve(n - i*i,dp);
            minCount = min(minCount, result);
        }

        return dp[n] = minCount;
    }

    int numSquares(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        return solve(n, dp);
    }
};

int main(){
  Solution s;
  s.numSquares(12);  
  return 0;
}
