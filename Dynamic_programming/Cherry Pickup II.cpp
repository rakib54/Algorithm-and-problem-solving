#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int m, n;
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid, int row, int c1, int c2){
        if(row >= m){
            return 0;
        }
        if(dp[row][c1][c2] != -1){
            return dp[row][c1][c2];
        }
        int cherry = grid[row][c1];  

        if(c1 != c2){ // if two are in same cell pick one
            cherry += grid[row][c2];
        }

        int ans = 0;
        for(int i = -1; i<=1; i++){ // robot1 options
            for(int j = -1; j <=1; j++){ // robot2 options
                int newRow = row + 1;
                int newC1 = c1 + i;
                int newC2 = c2 + j;

                if(newC1 >= 0 && newC1 < n && newC2 >= 0 && newC2 < n) // check column are not out of bound
                    ans = max(ans, solve(grid, newRow, newC1, newC2));
            }
        }
        cherry += ans;
        return dp[row][c1][c2] = cherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, n-1);
    }
};

int main(){
  Solution s;
  vector<vector<int>> grid{{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
  s.cherryPickup(grid);
  return 0;
}

// Time Complexity -> O(m * n * n)
// Space Complexity -> O(m * n * n)