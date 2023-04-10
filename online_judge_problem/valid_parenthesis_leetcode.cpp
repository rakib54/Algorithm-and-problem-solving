#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  string s = "()[]{}";
  stack<char>st;
  for(int i=0;i<s.size();i++){
      if(st.empty()){
          st.push(s[i]);
      }
      else if(st.top() == '(' && s[i] == ')' || st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']')
      st.pop();
      else {
          st.push(s[i]);
      }
  }
  cout<<st.empty();

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
