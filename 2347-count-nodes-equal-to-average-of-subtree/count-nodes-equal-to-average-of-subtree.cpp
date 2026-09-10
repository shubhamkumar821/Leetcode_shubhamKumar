class Solution {
public:

    int averageOfSubtree(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int average = dfs(root) / no_of_nodes(root);

        int ans = 0;

        if (average == root->val)
            ans++;

        ans += averageOfSubtree(root->left);
        ans += averageOfSubtree(root->right);

        return ans;
    }

    int no_of_nodes(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int nodes = 1 + no_of_nodes(root->left)
                      + no_of_nodes(root->right);

        return nodes;
    }

    int dfs(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int sum = dfs(root->left)
                + dfs(root->right)
                + root->val;

        return sum;
    }
};