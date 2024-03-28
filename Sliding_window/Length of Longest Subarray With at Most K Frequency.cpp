#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int i = 0, j = 0;
        int result = 0;

        while(j < n){
            mp[nums[j]]++;

            while(i < j && mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }

            result = max(result, j - i + 1);

            j++;
        }

        return result;
    }
};

int main(){
  Solution s;
  vector<int>nums{1,2,3,1,2,3,1,2};
  s.maxSubarrayLength(nums,2);
  return 0;
}
