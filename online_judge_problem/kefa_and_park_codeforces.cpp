#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>adj_list[N];
int arr[N];
int n,m;
int cnt = 0;

void dfs(int root, int vnode,int num){
    if(num > m){
        return;
    }
    bool flag = false;
    for(int adj_node: adj_list[root]){
        if(adj_node == vnode) continue;
        flag = true;
        if(arr[adj_node] == 1){
            dfs(adj_node,root,num+1);
        }
        else dfs(adj_node,root,0);
    }
    if(!flag && num<=m) {
        cnt++;
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(1,-1,arr[1]);
    cout<<cnt<<endl;

    return 0;
}
