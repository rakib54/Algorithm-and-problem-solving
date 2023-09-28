#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> sortArrayByParity(vector<int> &nums)
  {
    int n = nums.size();

    int i = 0, j = 0;

    while (i < n)
    {
      if (nums[i] % 2 == 0)
      {
        swap(nums[i], nums[j]);
        j++;
      }
      i++;
    }

    return nums;
  }
};

int main()
{
  Solution solution;
  vector<int> nums{1, 3, 2, 4};
  solution.sortArrayByParity(nums);

  return 0;
}

/*
O(N) space -->

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        int i = 0, j = n-1;

        for(int k = 0; i<=j && k< n; k++){
            if(nums[k] % 2 == 0){
                result[i] = nums[k];
                i++;
            }
            else {
                result[j] = nums[k];
                j--;
            }
        }

        return result;
    }
};


--> with comparator function

class Solution {
public:
    static bool comparator(int &nums1, int &nums2){
        return (nums1 % 2) < nums2 % 2 ;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comparator);

        return nums;
    }
};
*/