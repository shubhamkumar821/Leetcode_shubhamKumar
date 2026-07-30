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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return func(preorder,i,INT_MAX);
        
    }
    TreeNode*func(vector<int>&A,int & i,int max_bound){
        if(i==A.size()|| A[i]>max_bound)return nullptr;
        TreeNode*root=new TreeNode(A[i++]);
        root->left=func(A,i,root->val);
        root->right=func(A,i,max_bound);
        return root;
    }
};