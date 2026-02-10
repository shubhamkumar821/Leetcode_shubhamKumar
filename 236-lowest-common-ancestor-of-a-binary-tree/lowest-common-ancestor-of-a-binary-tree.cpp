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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   return LCA(root,p,q);

        
    }
    TreeNode*LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr)return nullptr;
           if (root == p || root == q) return root;

        if(hasNode(root->left,p)&& hasNode(root->right,q))
        return root;

         if(hasNode(root->left,q)&& hasNode(root->right,p))
        return root;

        TreeNode*l=LCA(root->left,p,q);
        TreeNode*r=LCA(root->right,p,q);

        if(l!=nullptr){
            return l;
        }
        return r;




    }

    bool hasNode(TreeNode*root,TreeNode*node){
        if(root==nullptr)return false;
        return root==node||hasNode(root->left,node)||hasNode(root->right,node);
    }
};
