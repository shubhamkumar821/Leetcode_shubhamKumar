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
vector<int>inod;
    bool findTarget(TreeNode* root, int k) {
        rec(root);
        int i=0;
        int j=inod.size()-1;
        while(i<j){
            if(inod[i]+inod[j]==k)return true;
            else if(inod[i]+inod[j]>k)j--;
            else{
                i++;
            }
        }
        return false;
        
    }
    void rec(TreeNode*root){
        if(root==nullptr)return ;
        rec(root->left);
        inod.push_back(root->val);
        rec(root->right);


    }
};