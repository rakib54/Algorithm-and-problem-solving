#include <bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin>>t;
    int c = 1;
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<"Case "<<c++<<":"<<endl;
        vector<pair<int,int>>adj_list[n];
        vector<int>d(n,INT_MAX);

        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj_list[u].push_back({v,w});
            adj_list[v].push_back({u,w});
        }
        int src;
        cin>>src;

        d[src] = 0;
        priority_queue<pair<long long,int>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            pair<long long,int> head = pq.top();
            pq.pop();
            int selected_node = head.second;
            int dis = head.first;

            if(dis > d[selected_node]) continue;

            for(auto adj_node: adj_list[selected_node]){
                int node = adj_node.first;
                int cost = adj_node.second;
                if(max(d[selected_node],cost) < d[node]){
                    d[node] = max(d[selected_node],cost);
                    pq.push({-d[node],node});
                }
            }
        }

        for(int i=0;i<n;i++){
            if(d[i] == INT_MAX){
                cout<<"Impossible"<<endl;
            }
            else cout<<d[i]<<endl;
        }
    }

    return 0;
}

