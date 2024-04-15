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
  string path = "";
  int sum = 0;

  void dfs(TreeNode *root, int &sum, int curr_sum)
  {
    if (root->left == NULL && root->right == NULL)
    { // leaf node
      curr_sum = curr_sum * 10 + root->val;
      sum += curr_sum;
      return;
    }
    curr_sum = curr_sum * 10 + root->val;

    if (root->left)
      dfs(root->left, sum, curr_sum);
    if (root->right)
      dfs(root->right, sum, curr_sum);
  }

  int sumNumbers(TreeNode *root)
  {
    int sum = 0;
    dfs(root, sum, 0);
    return sum;
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

  s.sumNumbers(node1);

  return 0;
}
