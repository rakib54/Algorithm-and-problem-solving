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
  long long kthLargestLevelSum(TreeNode *root, int k)
  {
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

    sort(levelSum.rbegin(), levelSum.rend());

    return k <= levelSum.size() ? levelSum[k - 1] : -1;
  }
};

int main()
{
  Solution s;
  TreeNode *root = new TreeNode(5);
  TreeNode *root2 = new TreeNode(10);
  TreeNode *root3 = new TreeNode(11);

  root->left = root2;
  root->right = root3;

  s.kthLargestLevelSum(root, 1);

  return 0;
}
