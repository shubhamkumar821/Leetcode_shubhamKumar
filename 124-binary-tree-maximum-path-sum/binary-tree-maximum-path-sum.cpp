class Solution {
public:
    int ans = INT_MIN;

    int rec(TreeNode* node) {
        if (!node) return 0;

        int left = max(0, rec(node->left));
        int right = max(0, rec(node->right));

        // path passing through current node
        ans = max(ans, left + right + node->val);

        // return best downward path
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        rec(root);
        return ans;
    }
};