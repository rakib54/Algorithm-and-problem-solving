#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void DFS(int ancestor, unordered_map<int,vector<int>>&adj, vector<vector<int>>&result, int currNode){

        for(int& neighbour: adj[currNode]){
            if(result[neighbour].empty() || result[neighbour].back() != ancestor){ // avoid duplicate
                result[neighbour].push_back(ancestor);
                DFS(ancestor, adj, result, neighbour);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>result(n);
        unordered_map<int,vector<int>>adj;

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        for(int i = 0; i < n; i++){
            int ancestor = i;
            DFS(ancestor, adj, result, i);
        }

        return result;
    }
};

int main(){
  Solution solution;
  vector<vector<int>>edges{{0,3},{0,4},{1,3}, {2,4},{2,7}, {3,5},{3,6},{3,7},{4,6}};
  int n = 8;
  solution.getAncestors(n, edges);
  return 0;
}
