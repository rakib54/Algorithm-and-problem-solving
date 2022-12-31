#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
vector<int>graph[N];
int visited[N];
int in_degree[N];

bool cycle_detection(){
    queue<int>q;
    int cnt = 0;

    for(int i=0;i<N;i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int head = q.front();
        q.pop();
        cnt++;
        for(int adj_node: graph[head]){
            in_degree[adj_node]--;
            if(in_degree[adj_node] == 0){
                q.push(adj_node);
            }
        }
    }
    return cnt!=N;
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        in_degree[v]++;
    }

    bool has_detected = cycle_detection();

    cout<<(has_detected ? "Cycle Found" : "Cycle Not Found");

    return 0;
}

/*
4 4
1 2
2 3
3 4
4 1
*/

