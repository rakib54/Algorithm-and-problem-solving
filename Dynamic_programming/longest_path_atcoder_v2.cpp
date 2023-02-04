#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<vector<int>>adj;
int dp[N];
int n,m;

int solve(int i){
    if(adj[i].size() == 0) return 1;
    int &ans = dp[i];
    if(~ans) return ans;

    ans = 0;
    for(auto it: adj[i]){
        ans = max(ans,solve(it));
    }
    return  ++ans;
}

int main(){
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    memset(dp,-1,sizeof(dp));
    int ans = -1;
    for(int g=1;g<=n;g++){
        ans = max(ans,solve(g));
    }
    cout<<ans-1<<endl;

    return 0;
}
