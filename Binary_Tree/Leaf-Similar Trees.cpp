#include <bits/stdc++.h>
using namespace std;
#define ll long long

  // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void inorder(TreeNode* root, string &s){
        if(!root) return;
        if(root->left == NULL && root->right == NULL){
            s += to_string(root->val) + "-";
        } 
        if(root->left){
            inorder(root->left,s);
        }
        if(root->right){
            inorder(root->right,s);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";

        inorder(root1,s1);
        inorder(root2,s2);

        if(s1 == s2){
            return true;
        }
        return false;
    }
};

int main(){

  return 0;
}
