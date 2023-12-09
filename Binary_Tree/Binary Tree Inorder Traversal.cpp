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
  vector<int> ans;
  vector<int> inorderTraversal(TreeNode *root)
  {
    if (root == NULL)
      return ans;

    inorderTraversal(root->left);
    ans.push_back(root->val);
    inorderTraversal(root->right);

    return ans;
  }
};

int main()
{
  TreeNode *root = new TreeNode(0);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);

  Solution s;
  s.inorderTraversal(root);
}
