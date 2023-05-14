#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  int n = 5, k = 3;
  
  int curr = 1;
  vector<int>visited(n+1, 0);
  int j = 1;
  visited[1] = 1;
  while(true){
    int away = (j * k) + curr;
    if(away <= n) {
      curr = away;
    }
    else if(away % n == 0){
      curr = n;
    }
    else {
      curr = away % n;
    }
    if(visited[curr] == 1){
        break;
    }
    else {
        visited[curr] = 1;
    }
    j++;
  }
  vector<int>v;
  for(int i=1;i<=n;i++){
      if(!visited[i]){
        v.push_back(i);
      }
  }
  for(int i: v){
    cout<<i<<" ";
  }
  

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
