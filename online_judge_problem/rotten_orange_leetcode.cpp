#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        int fresh = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty() && fresh!=0){
            int s = q.size();
            for(int i=0;i<s;i++){
                pair<int,int> val = q.front();
                q.pop();
                int x = val.first;
                int y = val.second;
                
                for(int i=0;i<4;i++){
                    int new_x = x+dx[i];
                    int new_y = y+ dy[i];
                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y] == 1){
                        grid[new_x][new_y] = 2;
                        q.push({new_x,new_y});
                        fresh--;
                    }
                }
            }
            cnt++;
        }

        return (fresh == 0 ? cnt: -1);
    }
};

/*
vector<vector<int>> grid1 ={{2,1,1}, {1,1,0},{0,1,1}};
vector<vector<int>> grid2 ={{2,1,1}, {0,1,1},{1,0,1}};
vector<vector<int>> grid ={{0,1}};
*/
