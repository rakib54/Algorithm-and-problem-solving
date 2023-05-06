#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

void solve(){
  vector<int>nums {2,3,3,4,6,7};
  int target = 12;

  sort(nums.begin(), nums.end());
  int n = nums.size();
  int count = 0;
  vector<int>powerOf2(n, 1);
  for(int i=1;i<n;i++){
      powerOf2[i] = powerOf2[i-1] * 2 % mod;
  }
  int left = 0, right = n-1;
  while(left <= right){
      if(nums[left] + nums[right] > target){
          right--;
      }
      else{
          count += powerOf2[right-left];
          count = count % mod;
          left++;
      }
  }
  cout<<count;

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
