#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    visited[i][j] = 0;
                }
            }
        }
        int dx[4] = {0, 0, -1, 1}; // direction to visit
        int dy[4] = {1, -1, 0, 0};
        while (!q.empty())
        {
            pair<int, int> val = q.front();
            q.pop();
            int x = val.first;
            int y = val.second;

            for (int i = 0; i < 4; i++)
            {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && visited[new_x][new_y] == -1)
                {
                    visited[new_x][new_y] = 1;
                    visited[new_x][new_y] = visited[x][y] + 1; // add 1 from the previously visited node whose value is 1.
                    q.push({new_x, new_y});
                }
            }
        }
        return visited;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> result = s.updateMatrix(mat);

    return 0;
}

/*

class Solution {
public:
    vector<vector<int>>directions{{1,0},{-1,0}, {0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>result(n, vector<int>(m, -1));
        queue<pair<int ,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            pair<int,int>p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();

            for(auto dir: directions){
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(new_x >=0 && new_x < n && new_y >= 0 && new_y < m && result[new_x][new_y] == -1){
                    result[new_x][new_y] = result[x][y] + 1;
                    q.push({new_x, new_y});
                }
            }

        }
        return result;
    }

};

*/
