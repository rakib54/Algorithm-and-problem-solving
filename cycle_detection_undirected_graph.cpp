#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<int>graph[N];
int visited[N];

bool has_cycle(int node,int parent){
    visited[node] = 1;

    for(int adj_node: graph[node]){
        if(adj_node == parent){
            continue;
        }
        else if(visited[adj_node] == 1){
            return true;
        }
        else if(visited[adj_node] == 0 && has_cycle(adj_node,node)){
            return true;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool cycle_detected = false;
    for(int i=0;i<=n;i++){
        if(visited[i] == 0 && has_cycle(i,-1)){
            cycle_detected = true;
            break;
        }
    }
    cout<<(cycle_detected ? "Cycle Detected": "No Cycle");


    return 0;
}

/*
3 2
1 2
2 3


test case 1:
5 6
0 1
1 2
1 3
2 3
2 4
4 5

test case 2:
5 5
0 1
1 2
1 3
2 4
4 5

*/
