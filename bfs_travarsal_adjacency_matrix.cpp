#include <bits/stdc++.h>
using namespace std;
const int N=100;
int adj_matrix[N][N];
int visited[N];

void bfs(int node){
    visited[node] = 1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int head = q.front();
        cout<<head<<" ";
        q.pop();
        for(int i=0;i<N;i++){
            if(adj_matrix[head][i] && visited[i] == 0){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){
    int nodes;
    cin>>nodes;
    for(int i=0;i<nodes;i++){
        int u,v;
        cin>>u>>v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    bfs(0);

//    for(int i=0;i<=nodes;i++){
//        for(int j=0;j<=nodes;j++){
//            cout<<adj_matrix[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    return 0;
}

/*
3
0 1
0 2
1 3

6
0 1
0 2
1 3
1 4
2 5
2 6


*/
