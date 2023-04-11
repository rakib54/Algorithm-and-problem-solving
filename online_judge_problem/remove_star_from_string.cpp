#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  string s = "leet**cod*e";
  stack<char>st;
  string ans="";
  for(char c: s){
      if(c == '*'){
          st.pop();
      }
      else st.push(c);
  }
  while(!st.empty()){
      ans+= st.top();
      st.pop();
  }
  reverse(ans.begin(),ans.end());

  cout<< ans;

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
