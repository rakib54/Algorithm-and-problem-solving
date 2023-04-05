#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> nums {3,7,1,6};
  long prefix = 0;
  long ans = INT_MIN;
  for(int i=0;i<nums.size();i++){
      prefix += nums[i];
      // To find prefix sum ceil val-> (prefix + n-1)/n -> replace n = i+1
      ans = max(ans, ((prefix + i)/ (i+1)));
  }
  
  cout<<  ans;


  return 0;
}