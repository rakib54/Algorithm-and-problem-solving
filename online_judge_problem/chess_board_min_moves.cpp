#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int dist[N][N];

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

bool isValid(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N) {
        return true;
    }
    return false;
}

int bfs(pair<int, int> src, pair<int, int> dst) {
    queue<pair<int, int>> q;
    q.push(src);


    dist[src.first][src.second] = 0;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        if (x == dst.first && y == dst.second) {
            return dist[x][y];
        }

        for (int i = 0; i < 8; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY) && dist[newX][newY] == -1) {
                q.push({newX, newY});
                dist[newX][newY] = dist[x][y] + 1;
            }
        }
    }

    return -1;
}

int main() {
    pair<int, int> src = {0, 0};
    pair<int, int> dst = {3, 3};
  
    memset(dist, -1, sizeof dist);

    cout << "Minimum number of moves: " << bfs(src, dst) << endl;
    return 0;
}
