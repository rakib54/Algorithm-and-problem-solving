#include <bits/stdc++.h>
using namespace std;

/*
determines whether it can be the adjacency matrix of a simple undirected graph
*/
int main(){
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    // if self loops
    for(int i=0;i<n;i++){
        if(mat[i][i]!=0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    // if not symmetric
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] != mat[j][i]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;
    return 0;
}

/*
3
0 1 1
1 0 1
1 1 0


3
0 1 1
1 0 1
0 1 0

*/