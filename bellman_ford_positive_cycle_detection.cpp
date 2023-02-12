#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const long long INF = 1e18;
vector<pair<int,int>> adj_list[N];
long long d[N];
int p[N];


int main(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        d[i] = INF;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
    }
    bool positive_cycle = false;
    int last_updated_node = -1;

    for(int i=1;i<=n;i++){
        for(int node=1;node<=n;node++){
            for(auto adj_node: adj_list[node]){
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if(d[u] + w > d[v]){
                    d[v] = d[u] + w;
                    p[v] = u;
                    if(i == n){
                        positive_cycle = true;
                        last_updated_node = v;  // last updated node should v
                    }
                }
            }
        }
    }

    if(positive_cycle){
        cout<<"Positive cycle detected"<<endl;
    }
    else {
        cout<<"NO Positive cycle"<<endl;
    }

    return 0;
}

/*
4 4
2 4 2
1 2 3
3 1 2
2 3 -1
*/
