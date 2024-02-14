#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pos;
        vector<int>neg;

        for(int num: nums){
            if(num < 0){
                neg.push_back(num);
            }else {
                pos.push_back(num);
            }
        }

        vector<int>result;

        for(int i = 0; i < n/2; i++){
            result.push_back(pos[i]);
            result.push_back(neg[i]);
        }

        return result;

    }
};

int main(){
  Solution solution;
  vector<int>nums{3,1,-2,-5,2,-4};
  solution.rearrangeArray(nums);
  
  return 0;
}
