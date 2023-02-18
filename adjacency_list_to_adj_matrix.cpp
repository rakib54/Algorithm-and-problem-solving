#include <bits/stdc++.h>
using namespace std;

void adjacencyListToMatrix(vector<vector<pair<int, int>>>& adj_list, int n,vector<vector<int>> &adjacency_Matrix) {
    for (int i = 0; i < n; i++) {
        for (auto& neighbor : adj_list[i]) {
            int j = neighbor.first;
            int weight = neighbor.second;
            adjacency_Matrix[i][j] = weight;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj_list(n+1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }
    
    vector<vector<int>> adjacency_Matrix(n, vector<int>(n, 0));

    adjacencyListToMatrix(adj_list, n,adjacency_Matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjacency_Matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
3 3
1 2 1
2 3 2
1 3 4
*/
