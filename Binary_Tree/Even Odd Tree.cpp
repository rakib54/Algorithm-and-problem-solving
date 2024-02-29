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
  bool isEvenOddTree(TreeNode *root)
  {
    int level = 0;
    queue<TreeNode *> q;
    q.push(root);
    if (root->val % 2 == 0)
    { // corner case
      return false;
    }
    unordered_map<int, vector<int>> mp;

    while (!q.empty())
    {
      int n = q.size();

      while (n--)
      {
        TreeNode *node = q.front();
        q.pop();

        mp[level].push_back(node->val);

        if (node->left)
        {
          q.push(node->left);
        }
        if (node->right)
        {
          q.push(node->right);
        }
      }
      level++;
    }

    for (auto element : mp)
    {
      if (element.first % 2 == 0)
      {
        if (element.second.size() == 1 && element.second[0] % 2 == 0)
        { // if 1 element in the level
          return false;
        }
        for (int i = 0; i < element.second.size() - 1; i++)
        {
          if (element.second[i] % 2 == 0 || element.second[i + 1] % 2 == 0)
          {
            return false;
          }
          if (element.second[i] > element.second[i + 1])
          {
            return false;
          }
          if (element.second[i] == element.second[i + 1])
          {
            return false;
          }
        }
      }
      else
      {
        if (element.second.size() == 1 && element.second[0] % 2 != 0)
        {
          return false;
        }
        for (int i = 0; i < element.second.size() - 1; i++)
        {
          if (element.second[i] % 2 != 0 || element.second[i + 1] % 2 != 0)
          {
            return false;
          }
          if (element.second[i] < element.second[i + 1])
          {
            return false;
          }
          if (element.second[i] == element.second[i + 1])
          {
            return false;
          }
        }
      }
    }
    return true;
  }
};

int main()
{

  return 0;
}
