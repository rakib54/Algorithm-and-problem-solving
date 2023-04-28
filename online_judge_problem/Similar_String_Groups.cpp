#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isSimilar(string s1, string s2){
        int count = 0;
        for(int i=0;i<s1.size(); i++){
            if(s1[i] != s2[i]){
                count++;
                if(count > 2){
                    return false;
                }
            }
        }
        return count == 0 || count == 2;
    }

    void dfs(string curr,vector<string>& strs, map<string,int>&visited){
        if(visited.find(curr) != visited.end()){
            return;
        }
        visited[curr] = 1;
        for(int i=0;i<strs.size(); i++){
            if(isSimilar(strs[i], curr)){
                dfs(strs[i], strs,visited);
            }
        }
    }

void solve(){
  vector<string> strs = {"tars","rats","arts","star"};
  int result = 0;
  if(strs.size() == 0) {
      cout<< 0;
      return;
  }
  map<string, int>visited;

  for(string s: strs){
      if(visited.find(s) == visited.end()){
          dfs(s,strs,visited);
          result++;
      }
  }
  cout<< result;

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
