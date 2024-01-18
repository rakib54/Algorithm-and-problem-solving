#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int dp[46];
    int solve(int i, int n){
        if(i > n){
            return 0;
        }
        if(i == n){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        int one_step = solve(i+1, n);
        int two_step = solve(i+2, n);

        return dp[i] = one_step + two_step;
    }
    int climbStairs(int n) {
        memset(dp, -1,sizeof(dp));
        return solve(0,n);
    }
};

int main(){
  Solution s;

  s.climbStairs(10);  
  return 0;
}
