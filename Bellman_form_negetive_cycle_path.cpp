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
    bool negative_cycle = false;
    int last_updated_node = -1;

    for(int i=1;i<=n;i++){
        for(int node=1;node<=n;node++){
            for(auto adj_node: adj_list[node]){
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if(d[u] + w < d[v]){
                    d[v] = d[u] + w;
                    p[v] = u;
                    if(i == n){
                        negative_cycle = true;
                        last_updated_node = v;  // last updated node should v
                    }
                }
            }
        }
    }

    if(negative_cycle){
        cout<<"YES"<<endl;
        int selected_node = last_updated_node;

        for(int i=1;i<=n-1;i++){  // traverse till n-1 to enter into cycle
            selected_node = p[selected_node];
        }
        int first_node = selected_node;
        vector<int>cycle;
        cycle.push_back(selected_node);

        while(true){
            selected_node = p[selected_node];
            cycle.push_back(selected_node);
            if(selected_node == first_node) break;
        }
        reverse(cycle.begin(),cycle.end());
        for(int node: cycle){
            cout<<node<<" ";
        }
        cout<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }

    return 0;
}

/*
test case:
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

 */