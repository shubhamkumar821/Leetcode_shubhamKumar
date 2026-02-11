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
    int goodNodes(TreeNode* root) {
            if(root == nullptr) return 0;
        return ch(root,root->val);
        
    }
    int ch(TreeNode*node,int val){
          if(node==nullptr){
            return 0;
          }
          int ans=0;
          if(node->val >= val){
            ans+=1;
          }
          int nextMax = max(val, node->val);
          ans += ch(node->left, nextMax);
          ans += ch(node->right, nextMax);
          return ans;
        
    }

};