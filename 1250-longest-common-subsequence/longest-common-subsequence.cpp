class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, text1, text2);
    }

    int rec(int i, int j, string &a, string &b) {
        if (i == a.size() || j == b.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j]; // Return memoized result

        if (a[i] == b[j]) {
            dp[i][j] = 1 + rec(i + 1, j + 1, a, b);
        } else {
            dp[i][j] = max(rec(i + 1, j, a, b), rec(i, j + 1, a, b));
        }

        return dp[i][j];
    }
};