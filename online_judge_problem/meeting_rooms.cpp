#include <bits/stdc++.h>
using namespace std;

int main(){ 
  vector<vector<int>> intervals{{0,30}, {5,10},{15,20}};
  // vector<vector<int>> intervals{{7,10}, {2,4}};
  int n = intervals.size();
  bool flag = true;

  sort(intervals.begin(), intervals.end());
  for(int i=1;i<n;i++){
    if(intervals[i-1][1] > intervals[i][0]){
      flag = false;
    }
  }

  if(flag){
    cout<<"True"<<endl;
  }
  else {
    cout<<"False"<<endl;
  }

  return 0;
}