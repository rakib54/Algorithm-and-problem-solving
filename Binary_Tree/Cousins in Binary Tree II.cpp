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

// TC->0(2n), SC->0(n + n)
class Solution
{
public:
  TreeNode *replaceValueInTree(TreeNode *root)
  {
    if (root == NULL)
    {
      return root;
    }
    queue<TreeNode *> q;
    q.push(root);
    vector<long long> levelSum;

    while (!q.empty())
    {
      int size = q.size();
      long long sum = 0;

      while (size--)
      {
        TreeNode *curr = q.front();
        q.pop();
        int val = curr->val;
        sum += val;
        if (curr->left != NULL)
        {
          q.push(curr->left);
        }
        if (curr->right != NULL)
        {
          q.push(curr->right);
        }
      }

      levelSum.push_back(sum);
    }

    q.push(root);
    root->val = 0;
    int idx = 1;

    while (!q.empty())
    {
      int n = q.size();

      while (n--)
      {
        TreeNode *curr = q.front();
        q.pop();

        int siblingSum = 0;

        if (curr->left)
        {
          siblingSum += curr->left->val;
        }
        if (curr->right)
        {
          siblingSum += curr->right->val;
        }

        if (curr->left)
        {
          curr->left->val = levelSum[idx] - siblingSum;
          q.push(curr->left);
        }
        if (curr->right)
        {
          curr->right->val = levelSum[idx] - siblingSum;
          q.push(curr->right);
        }
      }
      idx++;
    }

    return root;
  }
};

// optimize solution , TC->0(n), SC->0(n)
class Solution2
{
public:
  TreeNode *replaceValueInTree(TreeNode *root)
  {
    if (root == NULL)
    {
      return root;
    }
    queue<TreeNode *> q;
    q.push(root);
    int levelSum = root->val;

    while (!q.empty())
    {
      int size = q.size();
      int nextLevelSum = 0;

      while (size--)
      {
        TreeNode *curr = q.front();
        q.pop();

        curr->val = levelSum - curr->val; // store sibling sum in curr
        int siblingSum = 0;

        if (curr->left)
        {
          siblingSum += curr->left->val;
        }
        if (curr->right)
        {
          siblingSum += curr->right->val;
        }

        if (curr->left)
        {
          nextLevelSum += curr->left->val;
          curr->left->val = siblingSum;
          q.push(curr->left);
        }

        if (curr->right)
        {
          nextLevelSum += curr->right->val;
          curr->right->val = siblingSum;
          q.push(curr->right);
        }
      }

      levelSum = nextLevelSum;
    }

    return root;
  }
};

int main()
{
  Solution s;

  return 0;
}
