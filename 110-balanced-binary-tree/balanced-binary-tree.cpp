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
  bool check =true;
    bool isBalanced(TreeNode* root) {
        rec(root);
        return check;
       
        
    }

    int rec(TreeNode*root){
        if(root == NULL){
            return 0;
        }
        

        int left=rec(root->left);
        int right=rec(root->right);

        if(abs(left-right)>1){
            check=false;
        }

        return 1+max(left,right);
    }
};