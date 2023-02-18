#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<pair<int,int>>adj_list[N];

int main(){
  vector<vector<int>> times{{2,1,1}, {2,3,1},{3,4,1}};
  int n = 4,k=2;
  for(auto i: times){
    adj_list[i[0]].push_back({i[1],i[2]});
  }
      
  vector<int>dist(n+1,1e9);
  priority_queue<pair<int,int>>pq;
  dist[0] = 0;
  pq.push({0,k});
  dist[k] = 0;

  while(!pq.empty()){
      pair<int,int>head = pq.top();
      pq.pop();
      int node_wt = head.first;
      int node = head.second;

      for(auto it: adj_list[node]){
          int adj_node = it.first;
          int wt = it.second;
          int curr = wt + node_wt;
          if(curr < dist[adj_node]){
              dist[adj_node] = curr;
              pq.push({curr,adj_node});
          }
      }
  }
  if(*max_element(dist.begin(), dist.end()) != 1e9){
      cout<< *max_element(dist.begin(), dist.end());
  }
  else cout<< -1;

  return 0;
}