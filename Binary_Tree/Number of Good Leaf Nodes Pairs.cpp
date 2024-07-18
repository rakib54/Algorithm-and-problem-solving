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
  void makeGraph(TreeNode *root, TreeNode *prev, unordered_map<TreeNode *, vector<TreeNode *>> &adj, unordered_set<TreeNode *> &leaf)
  {
    if (root == NULL)
    {
      return;
    }
    if (root->left == NULL && root->right == NULL)
    { // leaf node
      leaf.insert(root);
    }

    if (prev != NULL)
    {
      adj[root].push_back(prev);
      adj[prev].push_back(root);
    }

    makeGraph(root->left, root, adj, leaf);
    makeGraph(root->right, root, adj, leaf);
  }
  int countPairs(TreeNode *root, int distance)
  {
    unordered_set<TreeNode *> leaf;
    unordered_map<TreeNode *, vector<TreeNode *>> adj;

    makeGraph(root, NULL, adj, leaf); // O(N)

    int count = 0; // count of leaf pairs

    for (auto &node : leaf)
    { // // O(N^2)
      // hit bfs
      queue<TreeNode *> q;
      unordered_set<TreeNode *> visited;
      q.push(node);
      visited.insert(node);

      for (int level = 0; level <= distance; level++)
      {
        int size = q.size();
        while (size--)
        {
          TreeNode *curr = q.front();
          q.pop();
          if (curr != node && leaf.find(curr) != leaf.end())
          {
            count++;
            visited.insert(curr);
          }

          for (auto &neighbour : adj[curr])
          {
            if (!visited.count(neighbour))
            {
              visited.insert(neighbour);
              q.push(neighbour);
            }
          }
        }
      }
    }

    return count / 2;
  }
};

int main()
{

  return 0;
}
