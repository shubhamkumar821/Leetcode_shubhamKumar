class Solution {
public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;

        // Store index of every element in inorder
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(inorder, postorder,
                     0, inorder.size() - 1,
                     0, postorder.size() - 1,
                     mp);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int ins, int inen,
                    int pos, int poen,
                    map<int, int>& mp) {

        // No elements
        if (ins > inen || pos > poen) {
            return nullptr;
        }

        // Last element of postorder is root
        TreeNode* root = new TreeNode(postorder[poen]);

        // Find root in inorder
        int inroot = mp[root->val];

        // Number of elements in left subtree
        int leftSize = inroot - ins;

        // Build RIGHT subtree first
        root->right = build(inorder, postorder,
                            inroot + 1, inen,
                            pos + leftSize, poen - 1,
                            mp);

        // Build LEFT subtree
        root->left = build(inorder, postorder,
                           ins, inroot - 1,
                           pos, pos + leftSize - 1,
                           mp);

        return root;
    }
};