#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int n = happiness.size();

        long long result = 0;
        int decreseValue = 1;

        for(int i = n-1; i>=0; i--){
            if(k == 0) {
                return result;
            }

            result += max(0, happiness[i]);
            k--;
            if(i > 0){
                happiness[i-1] = max(0, happiness[i-1] - decreseValue);
            }
            decreseValue++;
        }

        return result;
    }
};

int main(){
  Solution solution;
  vector<int>nums{1,2,3,4,5,7,8};
  int k = 4;

  solution.maximumHappinessSum(nums,k);
  return 0;
}
