#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    // count of distinct k elements
    int slidingWindow(vector<int>& nums, int k){
        unordered_map<int,int>mp;
        int n = nums.size();

        int i =0, j = 0, count = 0;

        while(j < n){
            mp[nums[j]]++;

            while(mp.size() > k){
                mp[nums[i]]--;

                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }

            count += j - i + 1;

            j++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums,k-1);
    }
};

int main(){
  Solution s;
  vector<int>nums{1,2,1,2,3};
  s.subarraysWithKDistinct(nums,2);
  return 0;
}
