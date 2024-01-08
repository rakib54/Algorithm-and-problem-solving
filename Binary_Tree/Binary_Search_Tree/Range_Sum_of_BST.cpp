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
  int rangeSumBST(TreeNode *root, int low, int high)
  {
    if (!root)
      return 0;

    if (root->val >= low && root->val <= high)
    {
      return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }

    if (root->val < low)
    {
      return rangeSumBST(root->right, low, high);
    }
    return rangeSumBST(root->left, low, high);
  }
};

int main()
{
  TreeNode *t1 = new TreeNode(10);
  t1->left = new TreeNode(5);
  t1->right = new TreeNode(15);
  int low = 7, high = 15;

  Solution s;
  s.rangeSumBST(t1, low, high);

  return 0;
}
