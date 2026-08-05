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
        if(root==nullptr)return true;
        int l=rec(root->left);
        int r=rec(root->right);

        if(abs(l-r)>1){
            return false;
        } 
        return isBalanced(root->left)&&isBalanced(root->right);       
    }
    int rec(TreeNode*root){
        if(root==nullptr)return 0;
        int ans=0;
        ans=max({ans,1+rec(root->right),1+rec(root->left)});
        return ans;
    }
};