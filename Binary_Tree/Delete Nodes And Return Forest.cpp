#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
  vector<TreeNode *> result;
  unordered_map<int, int> mp;
  void solve(TreeNode *&root)
  {
    if (root == NULL)
    {
      return;
    }
    // post order travarsal
    solve(root->left);
    solve(root->right);

    if (mp.find(root->val) != mp.end())
    {
      if (root->left)
        result.push_back(root->left);
      if (root->right)
        result.push_back(root->right);
      root = NULL;
    }
  }
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
  {

    for (int node : to_delete)
    {
      mp[node]++;
    }

    solve(root);
    if (root)
      result.push_back(root);

    return result;
  }
};

int main()
{
  Solution s;
  TreeNode *node1 = new TreeNode(3);
  TreeNode *node2 = new TreeNode(9);
  TreeNode *node3 = new TreeNode(15);

  node1->left = node2;
  node1->right = node3;

  node2->left = NULL;
  node2->right = NULL;
  node3->left = NULL;
  node3->right = NULL;
  vector<int> delNode{9};
  s.delNodes(node1, delNode);

  return 0;
}
