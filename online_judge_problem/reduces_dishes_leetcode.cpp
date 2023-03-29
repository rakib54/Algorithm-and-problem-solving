#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int>satisfaction{-1,-8,0,5,-9};
  int ans = 0;
  int sum = 0;
  sort(satisfaction.rbegin(), satisfaction.rend());
  
  for(int i=0;i<satisfaction.size(); i++){
      if(sum + satisfaction[i] > 0){
          ans += sum + satisfaction[i];
          cout<<"ans: "<<ans<<" ";
          sum += satisfaction[i];
          cout<<"sum: "<<sum<<" "<<endl;
      }
  }


  return 0;
}

/*
    // prefix sum

    int n = satisfaction.size();
    sort(satisfaction.rbegin(), satisfaction.rend());
    vector<int>sum;
    sum = satisfaction;

    for(int i=1;i<n; i++){  
        sum[i] += sum[i-1];   // prefix sum 
    }
    int mx = 0, currsum = 0;
    for(int i=0;i<n;i++){
        currsum += sum[i];
        mx = max(mx,currsum);
    }
    return mx;
  
*/