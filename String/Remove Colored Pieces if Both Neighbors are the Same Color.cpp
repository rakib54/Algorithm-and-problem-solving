#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int alice = 0, bob = 0;
        int countA = 0, countB = 0;
        int resultA = 0, resultB = 0;


        for(int i = 0; i < n; i++){
            if(colors[i] == 'B' || i == n){
                if(countA >= 3)
                    resultA += countA - 2;
                countA = 0;
                countB++;
            }
            if(colors[i] == 'A' || i == n){
                if(countB >= 3)
                    resultB += countB - 2;
                countB = 0;
                countA++;
            }
        }

        resultA += max(0, countA - 2);
        resultB += max(0, countB - 2);
        
        if(resultA > resultB){ // if alice wins
            return true;
        }
        
        return false; // if draw or bob wins (for draw bob wins because alice start first)
    }
};

int main(){
  Solution solution;
  solution.winnerOfGame("AAABBBBBAAAAAA");
  
  return 0;
}
