#include <bits/stdc++.h>
using namespace std;
#define ll long long

//  Definition for a binary tree node.
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
  bool findPath(TreeNode *root, int target, string &path)
  {
    if (root == NULL)
    {
      return false;
    }
    if (root->val == target)
    {
      return true;
    }
    path.push_back('L');
    if (findPath(root->left, target, path))
    {
      return true;
    }
    path.pop_back(); // backtrack
    path.push_back('R');
    if (findPath(root->right, target, path))
    {
      return true;
    }
    path.pop_back(); // backtrack
    return false;
  }
  string getDirections(TreeNode *root, int startValue, int destValue)
  {
    string rootToSrc = "";
    string rootToDest = "";

    findPath(root, startValue, rootToSrc);
    findPath(root, destValue, rootToDest);

    int i = 0, j = 0;
    while (i < rootToSrc.size() && j < rootToDest.size())
    {
      if (rootToSrc[i] == rootToDest[j])
      {
        i++;
        j++;
      }
      else
      {
        break;
      }
    }
    string path = "";
    for (int k = i; k < rootToSrc.size(); k++)
    {
      path += 'U';
    }
    path += rootToDest.substr(j, rootToDest.size());

    return path;
  }
};

int main()
{
  Solution s;
  TreeNode *node1 = new TreeNode(1);
  TreeNode *node2 = new TreeNode(2);
  TreeNode *node3 = new TreeNode(3);

  node1->left = node2;
  node1->right = node3;

  s.getDirections(node1, 3, 1);

  return 0;
}
