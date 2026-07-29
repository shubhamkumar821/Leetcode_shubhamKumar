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
    bool isValidBST(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr)return true;
        

      return valid_bst(root, LLONG_MIN, LLONG_MAX);
        
    }
    bool valid_bst(TreeNode*root,long long min_value,long long max_value){
        if(root==nullptr)return true;
        if(root->val>=max_value || root->val<=min_value)return false;
        return valid_bst(root->left,min_value,root->val)&& valid_bst(root->right,root->val,max_value);
    }
};