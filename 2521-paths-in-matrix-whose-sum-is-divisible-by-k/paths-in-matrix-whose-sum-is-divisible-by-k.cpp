class Solution {
public:
    int m, n, K;
    vector<vector<int>> g;
    vector<vector<vector<int>>> dp;
    const int MOD = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        g = grid;
        K = k;
        m = grid.size();
        n = grid[0].size();

        dp = vector<vector<vector<int>>>(
            m, vector<vector<int>>(n, vector<int>(k, -1))
        );

        return rec(0, 0, g[0][0] % K);
    }

    int rec(int i, int j, int rem) {
        if (i >= m || j >= n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return (rem == 0);

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        long long ways = 0;

        // move down
        if (i + 1 < m) {
            ways += rec(i + 1, j, (rem + g[i + 1][j]) % K);
        }

        // move right
        if (j + 1 < n) {
            ways += rec(i, j + 1, (rem + g[i][j + 1]) % K);
        }

        return dp[i][j][rem] = ways % MOD;
    }
};


