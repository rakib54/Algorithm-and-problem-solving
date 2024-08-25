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
  void solve(TreeNode *root, vector<int> &result)
  {
    if (root == NULL)
    {
      return;
    }
    // post order --> left right root
    solve(root->left, result);
    solve(root->right, result);
    result.push_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> result;
    solve(root, result);

    return result;
  }
};

int main()
{
  Solution solution;
  TreeNode *root = new TreeNode(1);
  TreeNode *root2 = new TreeNode(NULL);
  TreeNode *root3 = new TreeNode(2);
  TreeNode *root4 = new TreeNode(3);

  root->left = root2;
  root->right = root3;
  root3->left = root4;

  solution.postorderTraversal(root);

  return 0;
}
