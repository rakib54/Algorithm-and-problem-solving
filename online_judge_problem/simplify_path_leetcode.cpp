#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  string path = "/../";
  // string path = "/home/";
  stack<string>st;
  for(int i=0;i<path.size();i++){
      if(path[i] == '/') continue; 
      string tmp = "";
      while(i<path.size() && path[i] != '/'){
          tmp+= path[i];
          i++;
      }
      if(tmp == ".") continue;
      else if(tmp == ".."){
          if(!st.empty()) st.pop();
      }
      else st.push(tmp);
  }
  string ans = "";
  while(!st.empty()){
      ans = '/' + st.top() + ans;
      st.pop();
  }
  if(ans.size() == 0) cout<< "/";
  cout<< ans;

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
