#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>> intervals{{0,30}, {5,10},{15,20}};
  int n = intervals.size();
  int ans = 0;
  vector<int>starts;
  vector<int>ends;

  for(auto interval: intervals){
    starts.push_back(interval[0]);
    ends.push_back(interval[1]);
  }

  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());

  for(int i=0, j=0; i<n;i++){
    if(starts[i] < ends[j]){
      ans++;
    }
    else j++;
  }

  cout<<ans<<endl;
  
  return 0;
}