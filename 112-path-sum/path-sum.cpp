class Solution {
public:
    int tar;

    bool hasPathSum(TreeNode* root, int targetSum) {
        tar = targetSum;
        return check(root, 0);
    }

    bool check(TreeNode* root, int sum) {
        // FIX 1: null check
        if (root == NULL) return false;

        sum += root->val;

        // FIX 2: check only at leaf
        if (root->left == NULL && root->right == NULL) {
            return sum == tar;
        }

        // FIX 3 + 4: use OR, don't overwrite
        return check(root->left, sum) || check(root->right, sum);
    }
};
