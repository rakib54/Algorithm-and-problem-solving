#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int n, m;
    void dfs(vector<vector<int>>& land, int i, int j, int &row, int &col){
        if(i < 0 || i >= n || j < 0 || j >= m || land[i][j] == 0){
            return;
        }
        land[i][j] = 0;  // visited
        row = max(row, i);
        col = max(col, j);

        dfs(land,i + 1, j, row,col);
        dfs(land,i - 1, j, row,col);
        dfs(land,i, j + 1, row,col);
        dfs(land,i, j - 1, row,col);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>result;
        n = land.size();
        m = land[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 1){
                    vector<int>v;
                    v.push_back(i);
                    v.push_back(j);
                    int row = 0, col = 0;
                    dfs(land,i,j,row,col);
                    v.push_back(row);
                    v.push_back(col);
                    result.push_back(v);
                }
            }
            
        }

        return result;
    }
};

int main(){
  Solution solution;
  vector<vector<int>>land{{1,0,0},{0,1,1},{0,1,1}};
  solution.findFarmland(land);
  
  return 0;
}
