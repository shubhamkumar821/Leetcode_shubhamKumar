class Solution {
public:
    vector<vector<int>> dp;

    int rec(int l, int r, vector<int>& nums) {

        if (l + 1 == r) return 0;

        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;

        for (int j = l + 1; j < r; j++) {

            int cost = nums[l] * nums[j] * nums[r];

            ans = max(ans,
                      rec(l, j, nums) +
                      rec(j, r, nums) +
                      cost);
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        dp.assign(n, vector<int>(n, -1));

        return rec(0, n - 1, nums);
    }
};