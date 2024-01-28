#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        //row wise cumulative sum

        for(int row = 0; row < rows; row++){
            for(int col = 1; col < cols; col++){
                matrix[row][col] += matrix[row][col-1];
            }
        }

        int result = 0;
        // find the no of subarays like leetcode 560

        for(int startCol = 0; startCol < cols; startCol++){
            for(int j = startCol; j < cols; j++){
                unordered_map<int,int>mp;
                mp[0] = 1; // cumulativesum = 0 initially
                
                int cumulativeSum = 0;

                for(int row = 0; row < rows; row++){
                    cumulativeSum += matrix[row][j] - (startCol > 0 ? matrix[row][startCol-1] : 0);

                    if(mp.find(cumulativeSum - target) != mp.end()){
                        result += mp[cumulativeSum - target];
                    }
                    mp[cumulativeSum]++;
                }
            }
        }
        return result;
    }
};

int main(){
  Solution solution;
  vector<vector<int>>matrix{{1,-1},{-1,1}};
  solution.numSubmatrixSumTarget(matrix,2);
  return 0;
}
