class Solution {
public:
    vector<int> arr;
    vector<vector<int>> dp;

    int rec(int i, int j) {
        if (i == j)
            return arr[i];

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int left = arr[i] - rec(i + 1, j);
        int right = arr[j] - rec(i, j - 1);

        return dp[i][j] = max(left, right);
    }

    bool stoneGame(vector<int>& piles) {
        arr = piles;
        int n = arr.size();

        dp.assign(n, vector<int>(n, INT_MIN));

        return rec(0, n - 1) > 0;
    }
};