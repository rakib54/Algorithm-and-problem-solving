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
  void inorder(TreeNode *root, vector<int> &v)
  {
    if (!root)
    {
      return;
    }
    inorder(root->left, v);  // left
    v.push_back(root->val);  // visit
    inorder(root->right, v); // right
  }

  TreeNode *solve(int left, int right, vector<int> &v)
  {
    if (left > right)
    {
      return NULL;
    }
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(v[mid]);
    root->left = solve(left, mid - 1, v);
    root->right = solve(mid + 1, right, v);

    return root;
  }
  TreeNode *balanceBST(TreeNode *root)
  {
    vector<int> v;
    inorder(root, v);
    int l = 0, r = v.size() - 1;

    return solve(l, r, v);
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  TreeNode *root2 = new TreeNode(2);
  TreeNode *root3 = new TreeNode(3);
  TreeNode *root4 = new TreeNode(4);
  root->left = NULL;
  root->right = root2;
  root2->left = NULL;
  root2->right = root3;
  root3->left = NULL;
  root3->right = root4;

  Solution s;
  s.balanceBST(root);

  return 0;
}
