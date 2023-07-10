#include <bits/stdc++.h>
using namespace std;
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
  int minDepth(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;

    while (!q.empty())
    {
      int s = q.size();
      depth++;

      for (int i = 0; i < s; i++)
      {
        TreeNode *node = q.front();
        q.pop();
        if (!node->left and !node->right)
        {
          return depth;
        }

        if (node->left)
        {
          q.push(node->left);
        }
        if (node->right)
        {
          q.push(node->right);
        }
      }
    }
    return depth;
  }
};