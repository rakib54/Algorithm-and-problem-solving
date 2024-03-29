#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());

        int i = 0, j = 0;
        int countMax = 0;
        long long result = 0;

        while(j < n){
            if(nums[j] == maxElement){
                countMax++;
            }

            while(countMax >= k){
                result += n - j;

                if(nums[i] == maxElement){
                    countMax--;
                }
                i++;
            }

            j++;
        }

        return result;
    }
};

int main(){
  Solution s;
  vector<int>nums{1,3,3,3,3,3};
  s.countSubarrays(nums,2);
  return 0;
}
