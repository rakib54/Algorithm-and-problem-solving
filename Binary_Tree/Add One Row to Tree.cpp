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
  void solve(TreeNode *root, int depth, int val, int curr)
  {
    if (curr == depth - 1)
    {
      TreeNode *tmpLeft = root->left;
      TreeNode *tmpRight = root->right;

      TreeNode *newRootLeft = new TreeNode(val);
      TreeNode *newRootRight = new TreeNode(val);

      root->left = newRootLeft;
      root->right = newRootRight;
      newRootLeft->left = tmpLeft;
      newRootRight->right = tmpRight;
      return;
    }

    if (root->left)
      solve(root->left, depth, val, curr + 1);
    if (root->right)
      solve(root->right, depth, val, curr + 1);
  }
  TreeNode *addOneRow(TreeNode *root, int val, int depth)
  {
    if (depth == 1)
    {
      TreeNode *newRoot = new TreeNode(val);
      newRoot->left = root;
      return newRoot;
    }

    solve(root, depth, val, 1);

    return root;
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
  int depth = 2;
  int val = 1;

  s.addOneRow(node1, depth, val);

  return 0;
}
