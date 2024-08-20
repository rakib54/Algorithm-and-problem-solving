#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int n ;
    int dp[101][2][101];
    int solveForAlice(int idx, int person, int M, vector<int>&piles){
        if(idx >= n){
            return 0;
        }
        int result = person == 1 ? -1 : INT_MAX;
        int stones = 0;

        if(dp[idx][person][M] != -1){
            return dp[idx][person][M];
        }

        for(int x = 1; x <= min(n - idx, 2 * M); x++){
            stones += piles[idx+x-1];

            if(person == 1){ // alice turn
                result = max(result, stones + solveForAlice(idx + x, 0, max(M, x), piles));
            }else {
                result = min(result, solveForAlice(idx + x, 1, max(M, x), piles));
            }
        }

        return dp[idx][person][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));

        return solveForAlice(0, 1,1,piles);
    }
};

int main(){
  Solution solution;
  vector<int>piles{2,7,9,4,4};
  solution.stoneGameII(piles);
  
  return 0;
}
