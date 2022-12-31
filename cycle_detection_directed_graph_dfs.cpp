#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int>adj[N];
int visited[N];

bool detect_cycle(int node){
    visited[node] = 1;
    for(int adj_node: adj[node]){
        if(visited[adj_node] == 0){  // unvisited node
            bool found_cycle = detect_cycle(adj_node);
            if(found_cycle){
                return true;
            }
        }
        else if(visited[adj_node] == 1){ // paused node
            return true;
        }
        else if(visited[adj_node] == 2){ // done node
            continue;
        }
    }
    visited[node] = 2;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool cycle_detected = false;
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            bool got_cycle = detect_cycle(i);
            if(got_cycle){
                cycle_detected = true;
                break;
            }
        }
    }
    cout<<(cycle_detected ? "Cycle detected" : "No Cycle")<<endl;


}

/*
4 4
1 2
2 3
3 4
4 1
*/
