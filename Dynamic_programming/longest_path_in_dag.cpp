#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int>adjlist[N];
int dp[N];
int root,target_node;

int max_distance(int node){
    if(node == root) return 0; //base case
    if(dp[node] != -1){  // memoization
        return dp[node];
    }
    int ans = 0;
    for(int adj_node: adjlist[node]){
        int parent_dist = max_distance(adj_node);
        ans = max(ans,parent_dist);
    }
    ans++;
    dp[node] = ans;
    return ans;
}

int main(){
    int n,e;
    cin>>n>>e;

    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        adjlist[v].push_back(u); // v is parent of u
    }
    for(int i=1;i<=n;i++){
        dp[i] = -1;
    }
    cin>>root>>target_node;
    cout<<max_distance(target_node)<<endl;

    return 0;
}

/**
test case:
4 4

1 3
3 4
1 4
4 2

1 2

output -> 3
*/
