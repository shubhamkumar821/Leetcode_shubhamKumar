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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        func(root,ans);
        return ans;
        
    }
    void func(TreeNode*root,vector<vector<int>>&ans){
        if (root == nullptr) return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>level;
           
           for(int i=0;i<n;i++){
             auto curr=q.front();
             q.pop();
             level.push_back(curr->val);

            if(curr->left!=nullptr){
                q.push(curr->left);
              //  level.push_back(root->left->val);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
               //level.push_back(root->left->val);
            }
}
   ans.push_back(level);
        }

    }
};