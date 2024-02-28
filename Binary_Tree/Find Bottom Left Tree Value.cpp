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

// Traditional bfs
class Solution
{
public:
  int result;
  void bfs(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *curr = q.front();
      q.pop();

      if (curr->right)
      {
        q.push(curr->right);
      }
      if (curr->left)
      {
        q.push(curr->left);
      }
      if (curr->left == NULL && curr->right == NULL)
      {
        result = curr->val;
      }
    }
  }
  int findBottomLeftValue(TreeNode *root)
  {
    bfs(root);
    return result;
  }
};

int main()
{
  TreeNode *node1 = new TreeNode(1);
  node1->left = new TreeNode(2);
  node1->right = new TreeNode(3);

  Solution s;
  s.findBottomLeftValue(node1);

  return 0;
}

// level order traversal
class Solution2
{
public:
  int result;
  void bfs(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      int n = q.size();

      while (n--)
      {
        TreeNode *curr = q.front();
        q.pop();
        result = curr->val;
        if (curr->right)
        {
          q.push(curr->right);
        }
        if (curr->left)
        {
          q.push(curr->left);
        }
      }
    }
  }
  int findBottomLeftValue(TreeNode *root)
  {
    bfs(root);
    return result;
  }
};

// dfs
class Solution3
{
public:
  int result;
  int maxDepth;
  void dfs(TreeNode *root, int currDepth)
  {
    if (!root)
      return;

    if (currDepth > maxDepth)
    {
      result = root->val;
      maxDepth = currDepth;
    }

    dfs(root->left, currDepth + 1);
    dfs(root->right, currDepth + 1);
  }
  int findBottomLeftValue(TreeNode *root)
  {
    maxDepth = -1;
    dfs(root, 0);
    return result;
  }
};