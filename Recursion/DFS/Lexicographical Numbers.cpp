#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void solve(int currNum , int &limit, vector<int>&result){
        if(currNum > limit){
            return;
        }
        result.push_back(currNum);
        for(int append = 0; append <= 9; append++){
            int newNum = (currNum * 10) + append;

            if(newNum > limit){ 
                break;
            }
            solve(newNum, limit, result);
        }

    }
    vector<int> lexicalOrder(int n) {
        vector<int>result;

        for(int start = 1; start <= 9; start++){
            solve(start,n , result);
        }

        return result;
    }
};

int main(){
  Solution solution;
  solution.lexicalOrder(113);
  
  return 0;
}
