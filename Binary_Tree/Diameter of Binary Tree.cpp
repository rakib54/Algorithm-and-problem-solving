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
  int solve(TreeNode *root, int &result)
  {
    if (root == NULL)
      return 0;

    int left = solve(root->left, result);
    int right = solve(root->right, result);

    result = max(result, left + right);

    return max(left, right) + 1;
  }
  int diameterOfBinaryTree(TreeNode *root)
  {
    if (root == NULL)
      return 0;

    int result = 0;
    solve(root, result);

    return result;
  }
};

int main()
{

  TreeNode *root = new TreeNode(0);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);

  Solution s;
  s.diameterOfBinaryTree(root);
  return 0;
}
