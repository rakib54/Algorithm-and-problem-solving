#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    const int mod = 1e9 + 7;
    int row, col;
    int dp[51][51][51];

    int solve(int i, int j, int maxMove){
        if(i >= row || j >= col || i < 0 || j < 0 ){
            return 1;
        }
        if( maxMove <= 0){
            return 0;
        }
        if(dp[i][j][maxMove] != -1){
            return dp[i][j][maxMove];
        }

        long long right = 0, left = 0, top = 0, bottom = 0;
        right = (right + solve(i, j + 1, maxMove - 1)) % mod;
        left = (left + solve(i+1, j, maxMove - 1)) % mod;
        top = (top + solve(i - 1, j, maxMove - 1)) % mod;
        bottom = (bottom + solve(i, j - 1, maxMove - 1)) % mod;

        return dp[i][j][maxMove] = (right + left + top + bottom) % mod;

    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        row = m;
        col = n;
        memset(dp, -1, sizeof(dp));
        
        return solve(startRow, startColumn, maxMove);
    }
};

int main(){
  Solution s;
  s.findPaths(1,3,3,0,1);
  return 0;
}
