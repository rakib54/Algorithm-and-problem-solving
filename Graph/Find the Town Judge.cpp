#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>outdegree(n + 1, 0);
        vector<int>indegree(n + 1, 0);

        for(auto vec: trust){
            int trust = vec[0];
            int to = vec[1];
            outdegree[trust]++;
            indegree[to]++;
        }

        for(int i = 1; i <= n ; i ++){
            if(outdegree[i] == 0 && indegree[i] == n-1){ // n- 1 = everybody trusts him except himself 
                return i;
            }
        }
        return -1;
    }
};

int main(){
  Solution s;
  vector<vector<int>>trust{{1,2},{2,3}};
  s.findJudge(3,trust);
  
  return 0;
}
