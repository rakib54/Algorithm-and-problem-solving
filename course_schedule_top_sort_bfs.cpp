#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int>graph[N];
int in_degree[N];
stack<int>st;
int n,m;

bool bfs(){
    queue<int>q;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int head = q.front();
        q.pop();
        cnt++;
        st.push(head);
        for(int adj_node: graph[head]){
            in_degree[adj_node]--;
            if(in_degree[adj_node] == 0){
                q.push(adj_node);
            }
        }
    }
    return cnt!=n;

}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        in_degree[v]++;
    }
    bool has_cycle_detected = bfs();
    stack<int>ans;
    while(!st.empty()){
        ans.push(st.top());
        st.pop();
    }
    if(has_cycle_detected){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        while(!ans.empty()){
            cout<<ans.top()<<" ";
            ans.pop();
        }
    }


    return 0;
}


/*
#test cases
5 3
1 2
3 1
4 5
*/