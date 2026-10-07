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

    int amountOfTime(TreeNode* root, int start) {

        map<TreeNode*,vector<TreeNode*>>mp;
        queue<TreeNode*>q;
        TreeNode*temp=nullptr;
        map<TreeNode*,int>vis;
        q.push(root);
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            if(x->val==start){
                temp=x;

            }
            if(x->left!=nullptr){
                mp[x->left].push_back(x);
                mp[x].push_back(x->left);
                q.push(x->left);

            }
            if(x->right!=nullptr){
                mp[x->right].push_back(x);
                mp[x].push_back(x->right);
                q.push(x->right);

                
            }
        }
       return dfs(temp,mp,vis);
       
        
    }
    int dfs(TreeNode*Node, map<TreeNode*,vector<TreeNode*>>&mp,map<TreeNode*,int>&vis){
        if(vis[Node]==1){
            return 0;
        }
        vis[Node]=1;
        int ans=0;
        for(auto x:mp[Node]){
            if(vis[x]==0){
             ans=max(ans,1+dfs(x,mp,vis));
            }
        }
        return ans;
    }
};