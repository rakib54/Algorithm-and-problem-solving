#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(int n){
  if(n<=1) return false;
  for(int i=2;i*i<=n;i++){
    if(n%i == 0){
      return false;
    }
  }
  return true;
}

void solve(){
  vector<vector<int>> nums {{1,2,3}, {5,6,7},{9,10,11}};
  int n = nums.size();
  int m = nums[0].size();

  vector<int> v;
  
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(i==j && isPrime(nums[i][j])){
            v.push_back(nums[i][j]);              
          }
      }
  }
  for(int i=0;i<n;i++){
    for(int j=m-1;j>=0;j--){
        if(i == j) continue;
        if(i+j == n-1 && isPrime(nums[i][j])){
          v.push_back(nums[i][j]);        
        }
    }
  }
  int largestPrime = 0;
  if(v.size() == 0){
    largestPrime =  0;
  }
  else {
    largestPrime =  *max_element(v.begin(),v.end());
  }
  cout<<largestPrime;

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
