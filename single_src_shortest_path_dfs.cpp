#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int>graph[N];
vector<int>visited(N,0);
int level[N];

void dfs(int node){
    visited[node] = 1;

    for(int adj_node: graph[node]){
        if(visited[adj_node] == 0){
            visited[adj_node] = 1;
            level[adj_node] =level[node] + 1;
            dfs(adj_node);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    int src;
    cin>>src;
    dfs(src);

    for(int i=0;i<n;i++){
        cout<<"Distance of node "<<i<<" : from source ->"<<level[i]<<" "<<endl;
    }

    return 0;
}

/*
5 4
1 0
0 2
1 3
3 4
*/
