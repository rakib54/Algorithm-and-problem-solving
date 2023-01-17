#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int INF = 1e9;
int dis[N];
set<pair<int,int>>s;

struct Node{
    int st,u,en;
};
vector<Node>adjlist[N];

int main (){
    int n,src,v,r;
    cin>>n>>src>>v>>r;

    for(int i=1;i<=n;i++){
        dis[i] = INF;
    }
    dis[src] = 0;
    s.insert({0,src});

    for(int i=0;i<r;i++){
        int start,departure,end_,time;
        cin>>start>>departure>>end_>>time;
        adjlist[start].push_back({departure,end_,time});
    }

    while(!s.empty()){
        auto head = *s.begin();
        int val = head.second;
        s.erase(head);
        if(val == v){
            cout<<dis[v];
            return 0;
        }

        for(Node node :adjlist[val]){
            if(dis[node.u] > node.en && dis[val] <= node.st){
                s.erase({dis[node.u],node.u});
                dis[node.u] = node.en;
                s.insert({dis[node.u], node.u});
            }
        }
    }
    cout<<-1<<endl;

    return 0;
}

/*
3
1 3
4
1 0 2 5
1 1 2 3
2 3 3 5
1 1 3 10

*/
