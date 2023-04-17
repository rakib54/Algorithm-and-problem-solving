#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  vector<int> candies{2,3,5,1,3}; 
  int extraCandies = 3;
  vector<bool>ans;
  int mxval = *max_element(candies.begin(), candies.end());

  for(int i=0;i<candies.size(); i++){
      if((candies[i] + extraCandies) >= mxval){
          ans.push_back(true);
      }
      else ans.push_back(false);
  }
  for(auto i: ans){
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
