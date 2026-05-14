class Solution {
public:

    vector<int> dp;

    int numSquares(int n) {

        dp.assign(n + 1, -1);

        return rec(0, n);
    }

    int rec(int sum, int n) {

        if(sum == n) {
            return 0;
        }

        if(sum > n) {
            return INT_MAX;
        }

        if(dp[sum] != -1) {
            return dp[sum];
        }

        int ans = INT_MAX;

        for(int i = 1; i * i <= n; i++) {

            int x = rec(sum + i * i, n);

            if(x != INT_MAX) {
                ans = min(ans, 1 + x);
            }
        }

        return dp[sum] = ans;
    }
};