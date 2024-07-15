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
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
  {
    TreeNode *root = new TreeNode(0);
    unordered_set<int> st;
    unordered_map<int, TreeNode *> mp;

    for (vector<int> node : descriptions)
    {
      int parent = node[0];
      int child = node[1];
      int isLeft = node[2];
      st.insert(child);

      if (!mp[parent])
      {
        mp[parent] = new TreeNode(parent);
      }
      if (!mp[child])
      {
        mp[child] = new TreeNode(child);
      }

      if (isLeft == 1)
      {
        mp[parent]->left = mp[child];
        mp[child] = mp[parent]->left;
      }
      else
      {
        mp[parent]->right = mp[child];
        mp[child] = mp[parent]->right;
      }
    }

    for (vector<int> node : descriptions)
    {
      int root = node[0];
      if (st.find(root) == st.end())
      {
        return mp[root];
      }
    }

    return NULL;
  }
};

int main()
{

  return 0;
}
