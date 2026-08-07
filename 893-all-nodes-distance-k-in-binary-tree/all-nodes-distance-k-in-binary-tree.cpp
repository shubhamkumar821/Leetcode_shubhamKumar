/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        q.push(root);
        map<TreeNode*,TreeNode*>Par;

        while(!q.empty()){
            auto x=q.front();
            q.pop();
            if(x->left!=nullptr){
                Par[x->left]=x;
                q.push(x->left);
            }

            if(x->right!=nullptr){
                Par[x->right]=x;
                q.push(x->right);
            }

        }

        queue<TreeNode*>Q;
        map<TreeNode*,bool>vis;
        vis[target]=true;
        int lev=0;
        Q.push(target);
        while(!Q.empty()){
            
            int sz=Q.size();
       
            if(lev++==k)break;
            for(int i=0;i<sz;i++){
                auto node=Q.front();
                     Q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    Q.push(node->left);
                }
                if(node->right && !vis[node->right] ){
                    vis[node->right]=true;
                    Q.push(node->right);
                }

                if(Par[node] && !vis[Par[node]]){
                    vis[Par[node]]=true;
                    Q.push(Par[node]);
                }
            }
        }
        vector<int>ans;
        while(!Q.empty()){
            ans.push_back(Q.front()->val);
            Q.pop();
        }
        return ans;

    
        
    }
};