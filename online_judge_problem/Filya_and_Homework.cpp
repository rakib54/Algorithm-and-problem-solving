#include <bits/stdc++.h>
using namespace std;

int main(){ 
  int n;
  cin>>n;
  vector<int> v;
  set<int>s;
  int sum = 0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    v.push_back(a);
    s.insert(a);
  }
  if(s.size() > 3){
    cout<<"NO"<<endl;
  }
  else if(s.size() <=2){
    cout<<"YES"<<endl;
  }
  else{
    int a = *s.begin();
    int b = *s.rbegin();
    auto it = s.begin();
    it++;
    int c = *it;
    // cout<<a<<" "<<b<<" "<<c<<endl;
    if(2 * c != a+b){
      cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
  }


  return 0;
}

// https://codeforces.com/problemset/problem/714/B