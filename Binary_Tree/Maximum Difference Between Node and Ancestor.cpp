#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
    int findMaxDiff(TreeNode* root, int maxV, int minV){
        if(root == NULL){
            return abs(maxV - minV);
        }
        maxV = max(maxV, root->val);
        minV = min(minV, root->val);

        int l = findMaxDiff(root->left, maxV, minV);
        int r = findMaxDiff(root->right, maxV, minV);

        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return findMaxDiff(root, root->val, root->val);
    }
};

int main(){
  
  return 0;
}
