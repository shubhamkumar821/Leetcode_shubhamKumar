/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }

      int lef=maxdis(root->left);
      int righ=maxdis(root->right);

      

      return isBalanced(root->left)&& isBalanced(root->right) &&  abs(lef - righ)<=1;
     
    }

    int maxdis(TreeNode*root){
        if(root==nullptr){
            return 0;
        }

        return max(1+maxdis(root->left),1+maxdis(root->right));

    }
};