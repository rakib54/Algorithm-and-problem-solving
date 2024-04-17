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
  void solve(TreeNode *root, string curr, string &ans)
  {
    if (!root)
      return;

    char ch = root->val + 'a';
    curr.push_back(ch);

    if (root->left == NULL && root->right == NULL)
    { // leaf node
      reverse(curr.begin(), curr.end());
      if (ans == "" || ans > curr)
      {
        ans = curr;
      }
      return;
    }

    solve(root->left, curr, ans);
    solve(root->right, curr, ans);
  }

  string smallestFromLeaf(TreeNode *root)
  {
    string ans;
    solve(root, "", ans);

    return ans;
  }
};

int main()
{
  Solution s;
  Solution s;
  TreeNode *root = new TreeNode(1);
  TreeNode *node2 = new TreeNode(9);
  TreeNode *node3 = new TreeNode(15);

  root->left = node2;
  root->right = node3;

  node2->left = NULL;
  node2->right = NULL;
  node3->left = NULL;
  node3->right = NULL;

  s.smallestFromLeaf(root);

  return 0;
}
