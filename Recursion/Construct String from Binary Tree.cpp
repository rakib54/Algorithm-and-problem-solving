#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  string tree2str(TreeNode *root)
  {
    if (root == NULL)
    {
      return "";
    }
    string result = to_string(root->val);

    string left = tree2str(root->left);
    string right = tree2str(root->right);

    if (root->left == NULL && root->right == NULL)
    {
      return result;
    }

    if (root->left == NULL)
    {
      return result + "()" + "(" + right + ")";
    }
    if (root->right == NULL)
    {
      return result + "(" + left + ")";
    }

    return result + "(" + left + ")" + "(" + right + ")";
  }
};

int main()
{

  return 0;
}

/*
  struct TreeNode {
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
  void solution(TreeNode *root, string &ans)
  {
    if (root == NULL)
      return;
    if (root->left == NULL && root->right == NULL)
    {
      ans += to_string(root->val);
      return;
    }
    ans += to_string(root->val);

    ans += '(';
    solution(root->left, ans);
    ans += ')';

    if (root->right != NULL)
    {
      ans += '(';
      solution(root->right, ans);
      ans += ')';
    }
  }
  string tree2str(TreeNode *root)
  {
    string ans = "";
    solution(root, ans);
    return ans;
  }
};
* /