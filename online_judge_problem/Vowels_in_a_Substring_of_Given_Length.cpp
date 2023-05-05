#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  string s = "abciiidef";
  int k = 3;
  unordered_set<char>vowels {'a','e','i','o','u'};

  int count_curr_window = 0;
  for(int i=0;i<k;i++){
    count_curr_window += vowels.count(s[i]);
  }
  int ans = count_curr_window;
  
  for(int i=k;i<s.size();i++){
    count_curr_window += vowels.count(s[i]) - vowels.count(s[i-k]);
    ans = max(ans, count_curr_window);
  }
  cout<<ans;
}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
