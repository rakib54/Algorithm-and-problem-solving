#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int count = 0;
        int i = 0, j = 0;

        int product = 1;

        while(j < n){
            product *= nums[j];

            while(product >= k){  // product should be less than k
                product /= nums[i];
                i++;
            }
         
            count += j - i + 1; // num of subarrays ending at j
            
            j++;
        }

        return count;
    }
};

int main(){
  Solution s;
  vector<int>nums{1,5,6,10};
  int k = 50;
  s.numSubarrayProductLessThanK(nums,k);
  return 0;
}
