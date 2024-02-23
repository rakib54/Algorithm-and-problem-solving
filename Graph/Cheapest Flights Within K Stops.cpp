#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>distance(n, INT_MAX);
        unordered_map<int, vector<pair<int,int>>>adj;

        for(auto &vec: flights){
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            adj[u].push_back({v, cost});
        }

        // BFS
        queue<pair<int,int>>q;  // storing src and destination
        q.push({src, 0});
        int steps = 0;
        distance[src] = 0;

        while(!q.empty() && steps <= k){
            int size = q.size();

            while(size --){
                int u = q.front().first;
                int cost = q.front().second;

                q.pop();

                for(pair<int,int>P: adj[u]){
                    int v = P.first;
                    int dis = P.second;

                    if(distance[v] > cost + dis){
                        distance[v] = cost + dis;
                        q.push({v, cost + dis});
                    }
                }
            }
            steps++;
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};

int main(){
  Solution solution;
  int n = 5;
  vector<vector<int>> flights{{0,1,100}, {1,2,100}, {2,0,100}, {1,3,600}, {2,3,200}};
  int src = 0;
  int dst = 3;
  int k = 1;

  solution.findCheapestPrice(n, flights, src,dst,k);
  return 0;
}
