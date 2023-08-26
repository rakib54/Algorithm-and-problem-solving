#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  int dp[1001][1001];
  int n;
  int solve(vector<vector<int>> &nums, int prev, int curr)
  {
    if (curr == n)
    {
      return 0;
    }

    if (prev != -1 && dp[prev][curr] != -1)
    {
      return dp[prev][curr];
    }

    int taken = 0;
    if (prev == -1 || nums[curr][0] > nums[prev][1])
    {
      taken = 1 + solve(nums, curr, curr + 1);
    }
    int not_taken = solve(nums, prev, curr + 1);

    if (prev != -1)
    {
      return dp[prev][curr] = max(taken, not_taken);
    }

    return max(taken, not_taken);
  }
  int findLongestChain(vector<vector<int>> &pairs)
  {
    n = pairs.size();
    sort(pairs.begin(), pairs.end());

    memset(dp, -1, sizeof(dp));

    return solve(pairs, -1, 0);
  }
};

int main()
{
  Solution solution;
  vector<vector<int>> pairs{{1, 2}, {2, 3}, {3, 4}};
  solution.findLongestChain(pairs);

  return 0;
}

/*
Tabulation -- >


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());

        // for(auto i: pairs){
        //     cout<<i[0] <<" "<<i[1]<<endl;
        // }
        int ans = 1;
        vector<int>dp(n,1);

        for(int i=0;i<n; i++){
            for(int j = 0; j < i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }

        return ans;
    }
};
*/
