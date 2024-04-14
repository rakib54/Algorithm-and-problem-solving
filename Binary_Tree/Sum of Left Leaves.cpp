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
  int solve(TreeNode *curr, TreeNode *parent)
  {
    if (curr == NULL)
    {
      return 0;
    }
    if (curr->left == NULL && curr->right == NULL)
    {
      if (parent != NULL && parent->left == curr)
      {
        return curr->val;
      }
    }

    int left = solve(curr->left, curr);
    int right = solve(curr->right, curr);

    return left + right;
  }

  int sumOfLeftLeaves(TreeNode *root)
  {
    return solve(root, NULL);
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

  s.sumOfLeftLeaves(node1);

  return 0;
}
