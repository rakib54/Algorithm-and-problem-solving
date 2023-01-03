// Problem: https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int>graph[N];
int visited[N];
vector<int>v;

void dfs(int node){
    visited[node] = 1;
    for(int adj_node: graph[node]){
        if(visited[adj_node] == 0){
            visited[adj_node] = 1;
            dfs(adj_node);
        }
    }
}

int main(){
    int n,m;
    int cnt = 0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            dfs(i);
            cnt++;
            v.push_back(i);
        }
    }
    cout<<cnt-1<<endl;
    for(int i=0;i<cnt-1;i++){
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }
    return 0;
}

/*
4 2
1 2
3 4
*/
