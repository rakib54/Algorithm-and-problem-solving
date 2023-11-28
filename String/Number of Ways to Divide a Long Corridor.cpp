#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    const int M = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int>seats_pos;
        long long result = 1;

        for(int  i = 0; i<n ;i++){
            if(corridor[i] == 'S'){
                seats_pos.push_back(i);
            }
        }
        if(seats_pos.size() % 2 != 0 or seats_pos.size() == 0){
            return 0;
        }
        int prev_end_idx = seats_pos[1];

        for(int i = 2; i<seats_pos.size(); i+=2){
            int len = seats_pos[i] - prev_end_idx;
            result = (result * len) % M;
            prev_end_idx = seats_pos[i+1];
        }

        return result;
    }
};

int main(){
  Solution solution;
  solution.numberOfWays("SSPPSPPS");
  return 0;
}
