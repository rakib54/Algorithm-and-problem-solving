#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int> >grid {{1,0,1}, {0,0,0},{1,0,1}};
  int n = grid.size();
  queue<pair<int , int>>q;
  vector<vector<int>>visited = grid;

  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          if(visited[i][j] == 1){
              q.push({i,j});
          }
      }
  }
  
  if(q.size() == n * n){ // if no water
      return -1;
  }
  vector<pair<int,int>>dir{{0,1}, {0,-1}, {-1,0}, {1,0}};
  int distance = -1;

  while(!q.empty()){
      int size = q.size();

      while(size--){
          auto [x,y] = q.front();
          q.pop();
          for(auto [dx, dy] : dir){
              int i = x + dx;
              int j = y + dy;
              if(i >=0 && i<n && j>=0 && j<n && visited[i][j] == 0){
                  visited[i][j] = 1;
                  q.push({i,j});
              }
          }
      } 
      distance++;
  }

  cout<<distance;

  return 0;
}