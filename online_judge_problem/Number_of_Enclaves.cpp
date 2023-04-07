#include <bits/stdc++.h>
using namespace std;

void dfs(int i,int j, vector<vector<int>>& grid){
    if(i<0 || i>=grid.size() || j<0 || j>= grid[i].size() || grid[i][j] !=1){
        return;
    } 
    grid[i][j] = 2; // marked as visited
    dfs(i,j-1,grid);
    dfs(i,j+1,grid);
    dfs(i+1,j,grid);
    dfs(i-1,j,grid);
}

int main(){
  vector<vector<int>> grid{{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
  int n = grid.size();
  int m = grid[0].size();

  // mark all boundary lane and all adjacent connected lane = 2
  for(int i=0;i<n;i++){
      dfs(i,0,grid);
      dfs(i,m-1,grid);
  }
  for(int j=0;j<m;j++){
      dfs(0,j,grid);
      dfs(n-1,j,grid);
  }
  int cnt = 0;
  // for(int i=0;i<n;i++){
  //     for(int j=0;j<m;j++){
  //         cout<<grid[i][j]<<" ";
  //     }
  //     cout<<endl;
  // }
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(grid[i][j] == 1){
            cnt++;
          }
      }
  }
  cout<< cnt;

}

// https://leetcode.com/problems/number-of-enclaves/description/