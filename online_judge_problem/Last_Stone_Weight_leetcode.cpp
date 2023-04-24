#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  vector<int> stones {2,7,4,1,8,1};
  priority_queue<int>pq;
  for(auto i: stones){
      pq.push(i);
  }
  while(!pq.empty()){
      if(pq.size() == 1) break;
      int first = pq.top();
      pq.pop();
      int second = pq.top();
      pq.pop();
      
      if(first != second){
          int nw = abs(second - first);
          pq.push(nw);
      }
      if(pq.empty()) cout<< 0;
  }
  cout<< pq.top();

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
