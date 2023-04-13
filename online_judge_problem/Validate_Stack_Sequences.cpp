#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  vector<int>pushed{1,2,3,4,5};
  vector<int>popped{4,5,3,2,1};
  stack<int>st;
  int j=0;
  for(int i=0;i<pushed.size();i++){
    st.push(pushed[i]);
    if(st.top() == popped[j]){
        while(!st.empty() && st.top() == popped[j]){
            st.pop();
            j++;
        }
    }
}

  // while(!st.empty()){
  //   cout<<st.top()<<" ";
  //   st.pop();
  // }
  // cout<<endl;

  cout<< (st.empty() ? "True": "false");

}

int main(){
  ll test = 1;
  while(test--){
    solve();
  }
  return 0;
}
