#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void dfs(vector<vector<int>>& stones, int idx, vector<bool>&visited){
        visited[idx] = true;

        for(int i = 0; i < stones.size(); i++){
            if(visited[i] == false && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1])){
                visited[i] = true;
                dfs(stones, i, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>visited(n , false);
        int group = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] == true){
                continue;
            }

            dfs(stones, i, visited);
            group++;
        }

        return n - group;
    }
};

int main(){
  Solution s;
  vector<vector<int>> stones{{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
  s.removeStones(stones);
  
  return 0;
}
