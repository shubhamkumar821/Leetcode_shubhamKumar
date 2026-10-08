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
    int countNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        int r=depthr(root);
        int l=depthl(root);
        if(r==l){
            return (1<<r)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }

    int depthr(TreeNode*root){
        if(root==nullptr)return 0 ;

        return 1+depthr(root->right);
    }

    int depthl(TreeNode*root){
        if(root==nullptr)return 0 ;

        return 1+depthl(root->left);
    }
};