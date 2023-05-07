#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  int n;
  cin>>n;
  int a;
  string s;
  priority_queue<int, vector<int>, greater<int>>pq11;
  priority_queue<int, vector<int>, greater<int>>pq01;
  priority_queue<int, vector<int>, greater<int>>pq10;

  for(int i=0;i<n;i++){
    cin>>a>>s;
    int val1 = s[0] - '0';
    int val2 = s[1] - '0';
    if(val1 && val2){
      pq11.push(a);
    }
    else if(val1 && !val2) pq10.push(a);
    else if(!val1 && val2) pq01.push(a);
  }
  if(pq11.empty() && (pq01.empty() || pq10.empty())){
    cout<<-1<<endl;
  }
  else if(pq11.empty()){
    cout<<pq01.top() + pq10.top()<<endl;
  }
  else if(!pq11.empty() && (pq01.empty() || pq10.empty())){
    cout<<pq11.top()<<endl;
  }
  else cout<<min(pq11.top(), (pq10.top()+pq01.top()))<<endl;
  
}

int main(){
  ll test = 1;
  cin>>test;
  while(test--){
    solve();
  }
  return 0;
}