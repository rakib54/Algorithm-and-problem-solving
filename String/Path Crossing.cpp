#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int,int>>directions;

        directions['N'] = {0,1};
        directions['W'] = {-1,0};
        directions['S'] = {0,-1};
        directions['E'] = {1,0};

        unordered_set<string>visited;

        visited.insert("0,0");

        int x = 0, y = 0;

        for(auto &ch: path){
            pair<int,int>curr = directions[ch];

            int dx = curr.first;
            int dy = curr.second;

            x += dx;
            y += dy;

            string s = to_string(x)+"," + to_string(y);

            if(visited.find(s) != visited.end()){
                return true;
            }
            visited.insert(s);
        }

        return false;
    }
};

int main(){
  Solution s;
  s.isPathCrossing("SWSE");  
  return 0;
}
