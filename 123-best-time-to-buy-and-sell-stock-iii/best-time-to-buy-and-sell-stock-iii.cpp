class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int rec(int i, int state, vector<int>& prices) {

        // All days processed
        if (i == n)
            return 0;

        // All 4 actions completed
        if (state == 4)
            return 0;

        if (dp[i][state] != -1)
            return dp[i][state];

        // Do nothing
        int skip = rec(i + 1, state, prices);

        int action;

        if (state == 0) {
            // First BUY
            action = -prices[i] + rec(i + 1, state + 1, prices);
        }
        else if (state == 1) {
            // First SELL
            action = prices[i] + rec(i + 1, state + 1, prices);
        }
        else if (state == 2) {
            // Second BUY
            action = -prices[i] + rec(i + 1, state + 1, prices);
        }
        else {
            // Second SELL
            action = prices[i] + rec(i + 1, state + 1, prices);
        }

        return dp[i][state] = max(skip, action);
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();

        // i = day
        // state = 0,1,2,3,4
        dp.assign(n, vector<int>(5, -1));

        return rec(0, 0, prices);
    }
};