#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Definition for a Node.
class Node
{
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val)
  {
    val = _val;
  }

  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

class Solution
{
public:
  void solve(Node *root, vector<int> &result)
  {
    vector<Node *> list;
    list = root->children;

    for (int i = 0; i < list.size(); i++)
    {
      if (list[i] == NULL)
        continue;

      solve(list[i], result);
      result.push_back(list[i]->val);
    }
  }
  vector<int> postorder(Node *root)
  {
    if (root == NULL)
    {
      return {};
    }
    vector<int> result;
    solve(root, result);
    result.push_back(root->val);

    return result;
  }
};

int main()
{
  Solution s;

  return 0;
}
