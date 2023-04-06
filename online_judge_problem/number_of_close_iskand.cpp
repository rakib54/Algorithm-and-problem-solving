#include <bits/stdc++.h>
using namespace std;

bool isClosed(int i,int j, vector<vector<int>>& grid){
        // check boundary line and boundary line is not allowed
      if(i<0 || i>=grid.size() || j<0 || j>= grid[i].size()){
          return false;
      }
      if(grid[i][j] == 1 || grid[i][j] == 2){
          return true;
      }
      grid[i][j] = 2; // marked as visited
      bool isleftClose = isClosed(i,j-1,grid);
      bool isrightClose = isClosed(i,j+1,grid);
      bool istopClose = isClosed(i+1,j,grid);
      bool isbottomClose = isClosed(i-1,j,grid);
      
      return isleftClose && isrightClose && istopClose && isbottomClose;
}

int main(){
  vector<vector<int>> grid{{1,1,1,1,1,1,1,0}, {1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0}, {1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
  int island = 0;
        
  for(int i=0;i<grid.size();i++){
      for(int j=0;j<grid[i].size();j++){
          if(grid[i][j] == 0 && isClosed(i,j,grid)){
              island++;
          }
      }
  }
  cout<< island;
  return 0;
}