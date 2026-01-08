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
    int maxLevelSum(TreeNode* root) {
        int level=1,sum=INT_MIN;
        int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            
              int qz=q.size();
              int cursum=0;

              for(int i=0;i<qz;i++){

              
            auto x=q.front();
              q.pop();
              cursum+=x->val;
              if(x->left)
              q.push(x->left);
              if(x->right)
              q.push(x->right);


              }
              if(cursum>sum){
                sum=cursum;
                ans=level;
                
              }
              level++;



        }
        return ans;
        
    }
};