#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  unordered_map<int, int> mp;
  void dfs(TreeNode *root)
  {
    if (!root)
      return;

    dfs(root->left);
    mp[root->val]++;
    dfs(root->right);
    mp[root->val]++;
  }
  vector<int> findMode(TreeNode *root)
  {
    dfs(root);

    int max_freq = 0;
    vector<int> result;

    for (auto &it : mp)
    {
      if (it.second > max_freq)
      {
        max_freq = it.second;
        result = {};
        result.push_back(it.first);
      }
      else if (it.second == max_freq)
      {
        result.push_back(it.first);
      }
    }

    return result;
  }
};

int main()
{

  return 0;
}

// Approach 2

/*

class Solution {
public:
    int curr_number  = 0;
    int curr_freq = 0;
    int max_freq = 0;
    vector<int>result;
    void dfs(TreeNode* root){
        if(!root) return ;

        dfs(root->left);

        if(root->val == curr_number) {
            curr_freq++;
        }else {
            curr_number = root->val;
            curr_freq = 1;
        }

        if(curr_freq > max_freq){
            result = {};
            max_freq = curr_freq;
        }
        if(curr_freq == max_freq){
            result.push_back(root->val);
        }

        dfs(root->right);

    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);

        return result;
    }
};
*/
