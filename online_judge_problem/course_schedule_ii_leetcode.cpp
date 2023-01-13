#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>adjlist[numCourses];
        vector<int>indegree(numCourses, 0);
        for(auto i: prerequisites){
            int u = i[0];
            int v = i[1];
            adjlist[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int head = q.front();
            q.pop();
            ans.push_back(head);

            for(int adj_node: adjlist[head]){
                indegree[adj_node]--;
                if(indegree[adj_node] == 0){
                    q.push(adj_node);
                }
            }
        }
        if(ans.size() == numCourses){
            return ans;
        }
        return {};
    }
};

/*
 numCourses = 2, prerequisites = [[1,0]]

 numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
*/