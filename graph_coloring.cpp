#include <bits/stdc++.h>
using namespace std;
const int N=2000;
vector<int>adj[N];
vector<int> visited(N+1,0);
int color[N];

bool dfs(int node){
    visited[node] = 1;
    for(int adj_node: adj[node]){
        if(visited[adj_node] == 0){
            if(color[node] == 1){
                color[adj_node] = 2;
            }
            else color[adj_node] = 1;
            bool is_bicolorable = dfs(adj_node);
            if(!is_bicolorable) {
                return false;
        }
        }
        else {
            if(color[node] == color[adj_node]){
                return false;
            }
        }
    }
    return true;

}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool is_bipartite  = true;
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            color[i] = 1;
            bool ok = dfs(i);
            if(!ok) {
                is_bipartite = false;
                break;
            }
        }
    }
    if(!is_bipartite) {
        cout<<"ImPossible"<<endl;
    }
    else {
        for(int i=1;i<=n;i++){
            cout<<color[i]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

/*
5 3
1 2
1 3
4 5
*/
