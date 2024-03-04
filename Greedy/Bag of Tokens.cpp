#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        if(n == 0 || tokens[0] > power) return 0; // edge case

        int ans = 0;

        int i = 0, j = n-1;
        int currScore = 0;

        while( i <= j){
            if(tokens[i] <= power){  // face-up
                currScore++;
                power -= tokens[i];
                i++;
            }else{  // face-down
                if(currScore == 0) continue;
                else {
                    power += tokens[j];
                    j--;
                    currScore--;
                }
            }

            ans = max(ans, currScore);
        }

        return ans;
    }
};

int main(){
  Solution solution;
  vector<int>tokens{100,200,300,400};
  int power = 200;
  solution.bagOfTokensScore(tokens, power);
  return 0;
}
