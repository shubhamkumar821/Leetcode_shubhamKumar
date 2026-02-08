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
    int maxDepth(TreeNode* root) {

        if(root==nullptr)
        return 0;
        int lef=maxdis(root->left);
        int righ=maxdis(root->right);
        return max(1+lef,1+righ);


        

        
    }

    int maxdis(TreeNode*root){
        if(root==nullptr)return 0;
        return max(1+maxdis(root->left),1+maxdis(root->right));
    }
};