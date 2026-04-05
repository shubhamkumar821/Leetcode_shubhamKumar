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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a1,a2;
        leaf(root1,a1);
        leaf(root2,a2);
        return a1==a2;
        
    }
    void leaf(TreeNode*r,vector<int>&ans){
        if(r==nullptr){
            return;
        }
        leaf(r->left,ans);
        leaf(r->right,ans);

        if(r->left==nullptr && r->right==nullptr){
            ans.push_back(r->val);

        }
    }
};