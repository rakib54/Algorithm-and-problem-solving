// Problem: https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int>adjList[N];
int visited[N], level[N];
int parent[N];

void bfs(int src){
    visited[src] = 1;
    level[src] = 1;
    parent[src] = -1;
    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int head = q.front();
        q.pop();
        for(int adj_node: adjList[head]){
            if(visited[adj_node] == 0){
                visited[adj_node] = 1;
                parent[adj_node] = head;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int src = 1;
    bfs(src);
    int destination = n;
    if(visited[destination] == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<level[destination]<<endl;
    vector<int>path;
    int selected_node = destination;
    while(true){
        path.push_back(selected_node);
        if(selected_node == src){
            break;
        }
        selected_node = parent[selected_node];
    }
    reverse(path.begin(),path.end());
    for(auto node:path){
        cout<<node<<" ";
    }

    return 0;
}
