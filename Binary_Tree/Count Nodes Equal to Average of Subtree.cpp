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
  int result = 0;
  int count = 0;
  pair<int, int> solve(TreeNode *root)
  {
    if (!root)
      return {0, 0};

    count++;
    auto left_p = solve(root->left);
    auto right_p = solve(root->right);

    int totalSum = left_p.first + right_p.first + root->val;
    int totalCount = left_p.second + right_p.second + 1; // 1 = root
    if (totalSum / totalCount == root->val)
    {
      result++;
    }
    return {totalSum, totalCount};
  }
  int averageOfSubtree(TreeNode *root)
  {
    solve(root);

    return result;
  }
};

int main()
{

  return 0;
}
