#include <bits/stdc++.h>
using namespace std;

int main(){ 
  int n,s;
  cin>>n>>s;
  int arr[n];
  int count = 0;
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  for(int i=1; i<n; i++){
    if(arr[i]- arr[i-1] <= s){
      count++;
    }
    else {
      count = 0;
    }
  }
  cout<<count+1;

  return 0;
}