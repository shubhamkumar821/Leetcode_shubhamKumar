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
vector<int>bfs;
    vector<int> rightSideView(TreeNode* root) {

        queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int sze=q.size();
        TreeNode*rightside=nullptr;

        for(int i=0;i<sze;i++){
            auto node=q.front();
            q.pop();
            if(node){
                rightside=node;
                q.push(node->left);
                q.push(node->right);
            }
        }
        if(rightside){
            bfs.push_back(rightside->val);
        }

    }
    return bfs;
        
    }

};
