#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  priority_queue<int, vector<int>, greater<int>>maxi; // min to max
  priority_queue<int>mini;  // default

  for(int i=0;i<m;i++){
    int a;
    cin>>a;
    maxi.push(a);
    mini.push(a);
  }
  int max_total = 0 , min_total = 0;

  for(int i=0;i<n;i++){
    int val = mini.top();
    mini.pop();
    max_total += val;
    val --;
    if(val > 0){
      mini.push(val);
    }
  }
  
  for(int i=0;i<n;i++){
    int val = maxi.top();
    maxi.pop();
    min_total += val;
    val --;
    if(val > 0){
      maxi.push(val);
    }
  }

  cout<<max_total<<" "<<min_total<<endl;
  return 0;
}