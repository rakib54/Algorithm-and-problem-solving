#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int N,K,M;
    const int MOD = 1e9 + 7;
    int dp[50][50][101];
    int solve(int idx, int lenlis, int lar){
        if(idx == N){
            if(lenlis == K){
                return 1;
            }
            return 0;
        }
        if(dp[idx][lenlis][lar] != -1){
            return dp[idx][lenlis][lar];
        }
        long long ans = 0;
        for(int i=1;i<=M;i++){
            if(i > lar){
                ans += solve(idx + 1, lenlis + 1, i) % MOD;
            }
            else {
                ans += solve(idx + 1, lenlis, lar);
            }
        }
        ans = ans % MOD;
        return dp[idx][lenlis][lar] = ans % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        K = k;
        M = m;
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0);
    }
};

int main(){
  Solution s;
  s.numOfArrays(2,3,1);
  
  return 0;
}
