#include <bits/stdc++.h>
using namespace std;
const int N = 51;
char grid[51][51];
int visited[51][51];
int n,m;
int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};

int dfs(int i,int j){
    int len = 1;
    for(int k=0;k<8;k++){
        int x = i+dx[k];
        int y = j+dy[k];
        int val =grid[x][y]- grid[i][j];
        if(x>=0 && x<n && y>=0 && y<m && val == 1 && visited[x][y] != 1){
            len = max(len,dfs(x,y)+1);
        }

    }
    visited[i][j] = 1;
    return len;
}

int main (){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int tc = 1;
    while(true){
        cin>>n>>m;

        if(n == 0 && m == 0) exit(0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j] = 0;
                cin>>grid[i][j];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] == 0 && grid[i][j] == 'A'){
                    ans = max(ans,dfs(i,j));
                }
            }
        }
        cout<<"Case "<<tc++<<": "<<ans<<"\n";

    }

    return 0;
}

