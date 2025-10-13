class Solution {
public:
    int n, m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    vector<vector<int>> vis;

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<int>>(n, vector<int>(m, 0));

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] != 0) {
                    int sum = 0;
                    dfs(i, j, grid, sum);
                    res = max(res, sum);
                }
            }
        }
        return res;
    }

    void dfs(int x, int y, vector<vector<int>>& grid, int& sum) {
        vis[x][y] = 1;
        sum += grid[x][y];  // accumulate fish count here

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (check(a, b, grid)) {
                dfs(a, b, grid, sum);
            }
        }
    }

    bool check(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || vis[i][j])
            return false;
        return true;
    }
};
