#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  string word1 = "abc";
  string word2 = "pqrs";

  string ans = "";
  int i = 0, j = 0;
  while(i < word1.size() && j < word2.size()){
      ans += word1[i];
      ans += word2[j];
      i++;
      j++;
  }
  while(i!= word1.size()){
      ans += word1[i];
      i++;
  }
  while(j!= word2.size()){
      ans += word2[j];
      j++;
  }

  cout<< ans;

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
