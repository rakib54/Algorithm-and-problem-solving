#include <bits/stdc++.h>
using namespace std;

const int N= 2e5;
vector<int>adj[N];
int visited[N];
stack<int>st;  // need stack for topological sort

void dfs(int node){
    visited[node] = 1;
    for(int adj_node: adj[node]){
        if(visited[adj_node] == 0){
            visited[adj_node] == 1;
            dfs(adj_node);
        }
    }
    st.push(node);
}

int main(){
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            dfs(i);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }


    return 0;
}

/*
# It will work only for acyclic graph

#test cases
5 3
1 2
3 1
4 5
*/
