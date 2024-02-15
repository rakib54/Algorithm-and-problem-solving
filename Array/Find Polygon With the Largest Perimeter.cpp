#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long>prefix(n,0);
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        long long ans = -1;

        for(int i = 2; i < n; i++){
            if(prefix[i-1] > nums[i]){
                ans = prefix[i];
            }
        }

        return ans;
    }
};

int main(){
  Solution s;
  vector<int>nums{1,12,1,2,5,50,3};
  s.largestPerimeter(nums);  
  return 0;
}
