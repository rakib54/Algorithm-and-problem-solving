#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

int solve(vector<pair<int,int>>&v, int i,int age){
    if(i == v.size()) return 0;
    if(dp[i][age] != -1){
        return dp[i][age];
    }
    // if we skip it
    int ans = solve(v,i+1,age);
//    cout<<"If skip "<<ans<<" ,";
    if(v[i].second >= age){
        int take_it = v[i].first + solve(v,i+1,v[i].second);
//        cout<<"take it: "<<take_it<<" ,";
        ans = max(ans, take_it);
    }
    dp[i][age] = ans;
    cout<<dp[i][age]<<" ";
    return ans;
}

int main(){
    vector<int>ages{8,9,10,1};
    vector<int>scores{1,2,3,5};
    int n = scores.size();
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({scores[i], ages[i]});
    }
    sort(v.begin(), v.end());
    memset(dp,-1,sizeof(dp));
    return solve(v,0,0);
}

/**
sorted by score

score -> age
5   ->    1
3   ->    10
2   ->    9
1   ->    8

we can not take juniors age of highest score.
Here age 1 has value 5. so skip this value.

Final value is 6.
*/
