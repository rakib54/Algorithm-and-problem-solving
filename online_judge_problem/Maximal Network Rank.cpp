#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maximal = 0;

        unordered_map<int, unordered_set<int>>adj;

        for(auto road : roads){
            int u = road[0];
            int v = road[1];

            adj[u].insert(v);
            adj[v].insert(u);
        }

        for(int i=0;i<n;i++){
            for(int j=i+1; j<n;j++){
                int ith_rank = adj[i].size();
                int jth_rank = adj[j].size();

                int total = ith_rank + jth_rank;
                if(adj[i].find(j) != adj[i].end()){
                    total -= 1;
                }
                maximal = max(maximal, total);
            }
        }
        return maximal;
        
    }
};

int main(){
  vector<vector<int>>roads{{0,1},{0,3},{1,2},{1,3}};
  int n = 4;

  Solution s;
  int result = s.maximalNetworkRank(n,roads);
  cout<<result<<endl;


  return 0;
}