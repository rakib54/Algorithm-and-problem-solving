#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        // populate first row from matrix
        for(int col = 0; col <n ; col++){
            dp[0][col] = matrix[0][col];
        }

        for(int row = 1; row < n; row++){
            for(int col = 0; col < n; col++){
                int a = INT_MAX, b = INT_MAX;
                if(col - 1 >= 0) {
                    a = dp[row-1][col-1];
                }
                if(col + 1 < n ) {
                    b = dp[row-1][col+1];
                }

                dp[row][col] = matrix[row][col] + min({a,b, dp[row-1][col]});
            }
        }

        int result = INT_MAX;
        // find last row minimum value for result
        for(int col = 0; col < n; col++){
            result  = min(dp[n-1][col],result);
        }

        return result;
    }
};

int main(){
  Solution solution;
  vector<vector<int> >matrix{{1,2,3},{4,5,6},{7,8,9}};
  solution.minFallingPathSum(matrix);
  
  return 0;
}

// recursion  + memo  + top-down
// code will (TLE) failed in last test case which is very large and recently added

class Solution {
public:
    int n , m;
    int dp[101][101];
    int solve(vector<vector<int>>& matrix, int i, int j){
        if(i == n - 1){
            return matrix[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int sum = matrix[i][j];
        int minSum = INT_MAX;

        if( i + 1 < n && j-1 >= 0){
            minSum = min(minSum , sum + solve(matrix, i + 1, j - 1));
        }
        if( i + 1 < n && j <m && j >=0 ){
            minSum = min(minSum, sum + solve(matrix, i + 1, j));
        }
        if( i + 1 < n && i >= 0 && j + 1 < m && j >=0 ){
            minSum = min(minSum , sum + solve(matrix, i + 1, j + 1));
        }

        return dp[i][j] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memset(dp, -1, sizeof(dp));

        int row = 0, minSum = INT_MAX;
        for(int col = 0; col < m; col++){
            minSum = min(minSum, solve(matrix, row, col));
        }

        return minSum;
    }
};


