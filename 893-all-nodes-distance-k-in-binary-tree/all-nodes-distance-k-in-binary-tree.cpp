class Solution {
public:
    map<TreeNode*, vector<TreeNode*>> mp;
    map<TreeNode*, int> vis;
    vector<int> ans;
    int K;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // Important: clear previous data
        mp.clear();
        vis.clear();
        ans.clear();

        K = k;

        queue<TreeNode*> q;
        TreeNode* temp = nullptr;

        q.push(root);

        // Build an undirected graph
        while (!q.empty()) {

            TreeNode* n = q.front();
            q.pop();

            // Target is already given as a pointer
            if (n == target) {
                temp = n;
            }

            // Left child
            if (n->left != nullptr) {
                mp[n].push_back(n->left);
                mp[n->left].push_back(n);

                q.push(n->left);
            }

            // Right child
            if (n->right != nullptr) {
                mp[n].push_back(n->right);
                mp[n->right].push_back(n);

                q.push(n->right);
            }
        }

        // Start DFS from target
        dfs(temp, 0);

        sort(ans.begin(), ans.end());

        return ans;
    }

    void dfs(TreeNode* root, int cnt) {

        if (root == nullptr)
            return;

        // We reached exactly distance K
        if (cnt == K) {
            ans.push_back(root->val);
            return;
        }

        vis[root] = 1;

        for (TreeNode* i : mp[root]) {

            if (vis[i] != 1) {
                dfs(i, cnt + 1);
            }
        }
    }
};