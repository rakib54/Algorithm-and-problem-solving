#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const int M = 1e5;
int dp[N][M];
int nums[N];

int subset_sum(int n,int target){
    // handle base case
    if(n == 0){
        if(target == 0) {
            return 1;
        }
        return 0;
    }
    // if the sum is already calculated
    if(dp[n][target] != -1){
        return dp[n][target];
    }
    int ans1 = subset_sum(n-1,target);
    if(target < nums[n]){
        dp[n][target] = ans1;
        return ans1;
    }
    int ans2 = subset_sum(n-1,target - nums[n]);
    int ans = ans1 || ans2;  // if any of the ans1 or ans2 are found it stores 1

    dp[n][target] = ans;
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;

    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    cout<<"1 or 0: "<<1 || 1<<'\n';
    memset(dp,-1,sizeof(dp));

    if(subset_sum(n,target)){
        cout<<"True"<<endl;
    }
    else cout<<"False"<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target; j++){
            cout<<dp[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}

/**
3 9
4 2 3
**/

