
class Solution {
public:
    
    int rob(TreeNode* root) {

        map<pair<TreeNode*,int>,int>dp;
        return rec(root, 0,dp);
    }

    int rec(TreeNode* root, int ch,map<pair<TreeNode*,int>,int>&dp) {
        if (root == nullptr) {
            return 0;
        }
      if(dp.find({root,ch})!=dp.end()){
        return dp[{root,ch}];

      }
        int ans = 0;

        if (ch == 0) {
            // Rob current node
            int take = root->val
                     + rec(root->left, 1,dp)
                     + rec(root->right, 1,dp);

            // Skip current node
            int skip = rec(root->left, 0,dp)
                     + rec(root->right, 0,dp);

            ans = max(take, skip);
        }
        else {
            // Parent was robbed, so skip current node
            ans = rec(root->left, 0,dp)
                + rec(root->right, 0,dp);
        }

        return dp[{root,ch}]=ans;
    }
};
